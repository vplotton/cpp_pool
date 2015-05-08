#ifndef SMARTPTR_HPP
# define SMARTPTR_HPP

# include <cassert>

template <class T>
class DefaultSPStorage
{
	public:
		typedef T* StoredType;    // the type of the pointee_ object
		typedef T* InitPointerType; /// type used to declare OwnershipPolicy type.
		typedef T* PointerType;   // type returned by operator->
		typedef T& ReferenceType; // type returned by operator*

		DefaultSPStorage() : pointee_(Default())
	{}

		// The storage policy doesn't initialize the stored pointer
		//     which will be initialized by the OwnershipPolicy's Clone fn
		DefaultSPStorage(const DefaultSPStorage&) : pointee_(0)
	{}

		template <class U>
			DefaultSPStorage(const DefaultSPStorage<U>&) : pointee_(0)
		{}

		DefaultSPStorage(const StoredType& p) : pointee_(p) {}

		PointerType operator->() const { return pointee_; }

		ReferenceType operator*() const { return *pointee_; }

		void Swap(DefaultSPStorage& rhs)
		{ std::swap(pointee_, rhs.pointee_); }

		// Accessors
		template <class F>
			friend typename DefaultSPStorage<F>::PointerType GetImpl(const DefaultSPStorage<F>& sp);

		template <class F>
			friend const typename DefaultSPStorage<F>::StoredType& GetImplRef(const DefaultSPStorage<F>& sp);

		template <class F>
			friend typename DefaultSPStorage<F>::StoredType& GetImplRef(DefaultSPStorage<F>& sp);

	protected:
		// Destroys the data stored
		// (Destruction might be taken over by the OwnershipPolicy)
		//
		// If your compiler gives you a warning in this area while
		// compiling the tests, it is on purpose, please ignore it.
		void Destroy()
		{
			delete pointee_;
		}

		// Default value to initialize the pointer
		static StoredType Default()
		{ return 0; }

	private:
		// Data
		StoredType pointee_;
};

	template <class T>
inline typename DefaultSPStorage<T>::PointerType GetImpl(const DefaultSPStorage<T>& sp)
{ return sp.pointee_; }

	template <class T>
inline const typename DefaultSPStorage<T>::StoredType& GetImplRef(const DefaultSPStorage<T>& sp)
{ return sp.pointee_; }

	template <class T>
inline typename DefaultSPStorage<T>::StoredType& GetImplRef(DefaultSPStorage<T>& sp)
{ return sp.pointee_; }


template <class P>
class RefCounted
{
	public:
		RefCounted():
			pCount_(new uintptr_t(1))
	{
		assert(pCount_!=0);
		*pCount_ = 1;
	}

		RefCounted(const RefCounted& rhs)
			: pCount_(rhs.pCount_)
		{}

		template <typename P1>
			RefCounted(const RefCounted<P1>& rhs)
			: pCount_(reinterpret_cast<const RefCounted&>(rhs).pCount_)
			{}

		P Clone(const P& val)
		{
			++*pCount_;
			return val;
		}

		bool Release(const P&)
		{
			if (!--*pCount_)
			{
				delete pCount_;
				pCount_ = NULL;
				return true;
			}
			return false;
		}

		void Swap(RefCounted& rhs)
		{ std::swap(pCount_, rhs.pCount_); }

		enum { destructiveCopy = false };

	private:
		// Data
		uintptr_t* pCount_;
};

struct AllowConversion
{
	enum { allow = true };

	void Swap(AllowConversion&)
	{}
};

struct DisallowConversion
{
	DisallowConversion()
	{}

	DisallowConversion(const AllowConversion&)
	{}

	enum { allow = false };

	void Swap(DisallowConversion&)
	{}
};

template <class P>
struct NoCheck
{
	NoCheck()
	{}

	template <class P1>
		NoCheck(const NoCheck<P1>&)
		{}

	static void OnDefault(const P&)
	{}

	static void OnInit(const P&)
	{}

	static void OnDereference(const P&)
	{}

	static void Swap(NoCheck&)
	{}
};

template <class P>
struct AssertCheck
{
	AssertCheck()
	{}

	template <class P1>
		AssertCheck(const AssertCheck<P1>&)
		{}

	template <class P1>
		AssertCheck(const NoCheck<P1>&)
		{}

	static void OnDefault(const P&)
	{}

	static void OnInit(const P&)
	{}

	static void OnDereference(P val)
	{ assert(val); (void)val; }

	static void Swap(AssertCheck&)
	{}
};

template <class P>
struct AssertCheckStrict
{
	AssertCheckStrict()
	{}

	template <class U>
		AssertCheckStrict(const AssertCheckStrict<U>&)
		{}

	template <class U>
		AssertCheckStrict(const AssertCheck<U>&)
		{}

	template <class P1>
		AssertCheckStrict(const NoCheck<P1>&)
		{}

	static void OnDefault(P val)
	{ assert(val); }

	static void OnInit(P val)
	{ assert(val); }

	static void OnDereference(P val)
	{ assert(val); }

	static void Swap(AssertCheckStrict&)
	{}
};

////////////////////////////////////////////////////////////////////////////////
// class template SmartPtr (declaration)
// The reason for all the fuss above
////////////////////////////////////////////////////////////////////////////////

template
<
typename T,
	 template <class> class OwnershipPolicy = RefCounted,
	 class ConversionPolicy = DisallowConversion,
	 template <class> class CheckingPolicy = AssertCheck,
	 template <class> class StoragePolicy = DefaultSPStorage
	 >
	 class SmartPtr;

	 ////////////////////////////////////////////////////////////////////////////////
	 // class template SmartPtrDef (definition)
	 // this class added to unify the usage of SmartPtr
	 // instead of writing SmartPtr<T,OP,CP,KP,SP> write SmartPtrDef<T,OP,CP,KP,SP>::type
	 ////////////////////////////////////////////////////////////////////////////////

	 template
	 <
	 typename T,
	 template <class> class OwnershipPolicy = RefCounted,
	 class ConversionPolicy = DisallowConversion,
	 template <class> class CheckingPolicy = AssertCheck,
	 template <class> class StoragePolicy = DefaultSPStorage
	 >
	 struct SmartPtrDef
{
	typedef SmartPtr
		<
		T,
	OwnershipPolicy,
	ConversionPolicy,
	CheckingPolicy,
	StoragePolicy
		>
		type;
};

////////////////////////////////////////////////////////////////////////////////
///  \class SmartPtr
///
///  \ingroup SmartPointerGroup
///
///  \param OwnershipPolicy  default =  RefCounted,
///  \param ConversionPolicy default = DisallowConversion,
///  \param CheckingPolicy default = AssertCheck,
///  \param StoragePolicy default = DefaultSPStorage
///  \param ConstnessPolicy default = LOKI_DEFAULT_CONSTNESS
///
///  \par IMPORTANT NOTE
///  Due to threading issues, the OwnershipPolicy has been changed as follows:
///
///     - Release() returns a boolean saying if that was the last release
///        so the pointer can be deleted by the StoragePolicy
///     - IsUnique() was removed
////////////////////////////////////////////////////////////////////////////////

template
<
typename T,
	 template <class> class OwnershipPolicy,
	 class ConversionPolicy,
	 template <class> class CheckingPolicy,
	 template <class> class StoragePolicy
	 >
	 class SmartPtr
	 : public StoragePolicy<T>
	   , public OwnershipPolicy<typename StoragePolicy<T>::InitPointerType>
	   , public CheckingPolicy<typename StoragePolicy<T>::StoredType>
	   , public ConversionPolicy
{
	typedef StoragePolicy<T> SP;
	typedef OwnershipPolicy<typename StoragePolicy<T>::InitPointerType> OP;
	typedef CheckingPolicy<typename StoragePolicy<T>::StoredType> KP;
	typedef ConversionPolicy CP;

	public:
	typedef typename SP::PointerType PointerType;
	typedef typename SP::StoredType StoredType;
	typedef typename SP::ReferenceType ReferenceType;

	typedef typename Select<OP::destructiveCopy,SmartPtr, const SmartPtr>::Result
		CopyArg;

	private:
	struct NeverMatched {};

	public:

	SmartPtr()
	{
		KP::OnDefault(GetImpl(*this));
	}

	explicit
		SmartPtr(ExplicitArg p) : SP(p)
	{
		KP::OnInit(GetImpl(*this));
	}

	SmartPtr(ImplicitArg p) : SP(p)
	{
		KP::OnInit(GetImpl(*this));
	}

	SmartPtr(CopyArg& rhs) : SP(rhs), OP(rhs), KP(rhs), CP(rhs)
	{
		GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
	}

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 SmartPtr(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs)
				 : SP(rhs), OP(rhs), KP(rhs), CP(rhs)
				 { GetImplRef(*this) = OP::Clone(GetImplRef(rhs)); }

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 SmartPtr(SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs)
				 : SP(rhs), OP(rhs), KP(rhs), CP(rhs)
				 {
					 GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
				 }

	SmartPtr(RefToValue<SmartPtr> rhs)
		: SP(rhs), OP(rhs), KP(rhs), CP(rhs)
	{}

	operator RefToValue<SmartPtr>()
	{ return RefToValue<SmartPtr>(*this); }

	SmartPtr& operator=(CopyArg& rhs)
	{
		SmartPtr temp(rhs);
		temp.Swap(*this);
		return *this;
	}

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 SmartPtr& operator=(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs)
				 {
					 SmartPtr temp(rhs);
					 temp.Swap(*this);
					 return *this;
				 }

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 SmartPtr& operator=(SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs)
				 {
					 SmartPtr temp(rhs);
					 temp.Swap(*this);
					 return *this;
				 }

	void Swap(SmartPtr& rhs)
	{
		OP::Swap(rhs);
		CP::Swap(rhs);
		KP::Swap(rhs);
		SP::Swap(rhs);
	}

	~SmartPtr()
	{
		if (OP::Release(GetImpl(*static_cast<SP*>(this))))
		{
			SP::Destroy();
		}
	}

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 friend void Release(SmartPtr<T1, OP1, CP1, KP1, SP1>& sp,
						 typename SP1<T1>::StoredType& p);

	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 friend void Reset(SmartPtr<T1, OP1, CP1, KP1, SP1>& sp,
						 typename SP1<T1>::StoredType p);
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 bool Merge( SmartPtr< T1, OP1, CP1, KP1, SP1 > & rhs )
				 {
					 if ( GetImpl( *this ) != GetImpl( rhs ) )
					 {
						 return false;
					 }
					 return OP::template Merge( rhs );
				 }

	PointerType operator->()
	{
		KP::OnDereference(GetImplRef(*this));
		return SP::operator->();
	}

	ConstPointerType operator->() const
	{
		KP::OnDereference(GetImplRef(*this));
		return SP::operator->();
	}

	ReferenceType operator*()
	{
		KP::OnDereference(GetImplRef(*this));
		return SP::operator*();
	}

	ConstReferenceType operator*() const
	{
		KP::OnDereference(GetImplRef(*this));
		return SP::operator*();
	}

	bool operator!() const // Enables "if (!sp) ..."
	{ return GetImpl(*this) == 0; }

	static inline T * GetPointer( const SmartPtr & sp )
	{ return GetImpl( sp ); }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 bool operator==(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
				 { return GetImpl(*this) == GetImpl(rhs); }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 bool operator!=(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
				 { return !(*this == rhs); }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 bool operator<(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
				 { return GetImpl(*this) < GetImpl(rhs); }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 inline bool operator > ( const SmartPtr< T1, OP1, CP1, KP1, SP1 > & rhs )
				 {
					 return ( GetImpl( rhs ) < GetImpl( *this ) );
				 }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 inline bool operator <= ( const SmartPtr< T1, OP1, CP1, KP1, SP1 > & rhs )
				 {
					 return !( GetImpl( rhs ) < GetImpl( *this ) );
				 }

	// Ambiguity buster
	template
		<
		typename T1,
			 template <class> class OP1,
			 class CP1,
			 template <class> class KP1,
			 template <class> class SP1
			 
				 >
				 inline bool operator >= ( const SmartPtr< T1, OP1, CP1, KP1, SP1 > & rhs )
				 {
					 return !( GetImpl( *this ) < GetImpl( rhs ) );
				 }

	private:
	// Helper for enabling 'if (sp)'
	struct Tester
	{
		Tester(int) {}
		void dummy() {}
	};

	typedef void (Tester::*unspecified_boolean_type_)();

	typedef typename Select<CP::allow, Tester, unspecified_boolean_type_>::Result
		unspecified_boolean_type;

	public:
	// enable 'if (sp)'
	operator unspecified_boolean_type() const
	{
		return !*this ? 0 : &Tester::dummy;
	}

	private:
	// Helper for disallowing automatic conversion
	struct Insipid
	{
		Insipid(PointerType) {}
	};

	typedef typename Select<CP::allow, PointerType, Insipid>::Result
		AutomaticConversionResult;

	public:
	operator AutomaticConversionResult() const
	{ return GetImpl(*this); }


////////////////////////////////////////////////////////////////////////////////
// friends
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// free comparison operators for class template SmartPtr
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///  operator== for lhs = SmartPtr, rhs = raw pointer
///  \ingroup SmartPointerGroup
////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator==(const SmartPtr<T, OP, CP, KP, SP1 >& lhs,
						 U* rhs)
				 { return GetImpl(lhs) == rhs; }

	////////////////////////////////////////////////////////////////////////////////
	///  operator== for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator==(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP1 >& rhs)
				 { return rhs == lhs; }

	////////////////////////////////////////////////////////////////////////////////
	///  operator!= for lhs = SmartPtr, rhs = raw pointer
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator!=(const SmartPtr<T, OP, CP, KP, SP >& lhs,
						 U* rhs)
				 { return !(lhs == rhs); }

	////////////////////////////////////////////////////////////////////////////////
	///  operator!= for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator!=(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP >& rhs)
				 { return rhs != lhs; }

	////////////////////////////////////////////////////////////////////////////////
	///  operator< for lhs = SmartPtr, rhs = raw pointer
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator<(const SmartPtr<T, OP, CP, KP, SP >& lhs,
						 U* rhs)
				 {
					 return ( GetImpl( lhs ) < rhs );
				 }

	////////////////////////////////////////////////////////////////////////////////
	///  operator< for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator<(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP >& rhs)
				 {
					 return ( GetImpl( rhs ) < lhs );
				 }

	////////////////////////////////////////////////////////////////////////////////
	//  operator> for lhs = SmartPtr, rhs = raw pointer
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator>(const SmartPtr<T, OP, CP, KP, SP >& lhs,
						 U* rhs)
				 { return rhs < lhs; }

	////////////////////////////////////////////////////////////////////////////////
	///  operator> for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator>(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP >& rhs)
				 { return rhs < lhs; }

	////////////////////////////////////////////////////////////////////////////////
	///  operator<= for lhs = SmartPtr, rhs = raw pointer
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator<=(const SmartPtr<T, OP, CP, KP, SP >& lhs,
						 U* rhs)
				 { return !(rhs < lhs); }

	////////////////////////////////////////////////////////////////////////////////
	///  operator<= for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator<=(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP >& rhs)
				 { return !(rhs < lhs); }

	////////////////////////////////////////////////////////////////////////////////
	///  operator>= for lhs = SmartPtr, rhs = raw pointer
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator>=(const SmartPtr<T, OP, CP, KP, SP >& lhs,
						 U* rhs)
				 { return !(lhs < rhs); }

	////////////////////////////////////////////////////////////////////////////////
	///  operator>= for lhs = raw pointer, rhs = SmartPtr
	///  \ingroup SmartPointerGroup
	////////////////////////////////////////////////////////////////////////////////

	template
		<
		typename T,
			 template <class> class OP,
			 class CP,
			 template <class> class KP,
			 template <class> class SP,
			 typename U
				 >
				 inline bool operator>=(U* lhs,
						 const SmartPtr<T, OP, CP, KP, SP >& rhs)
				 { return !(lhs < rhs); }
};


////////////////////////////////////////////////////////////////////////////////
///  specialization of std::less for SmartPtr
///  \ingroup SmartPointerGroup
////////////////////////////////////////////////////////////////////////////////

#endif // end file guardian

