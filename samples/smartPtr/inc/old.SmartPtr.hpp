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
		RefCounted()
			: pCount_(new unsigned int(1))
	{
		assert(pCount_!=0);
		*pCount_ = 1;
	}

		RefCounted(const RefCounted& rhs)
			: pCount_(rhs.pCount_)
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

template
<
typename T,
	 template <class> class OwnershipPolicy = RefCounted,
	 class ConversionPolicy = DisallowConversion,
	 template <class> class CheckingPolicy = AssertCheck,
	 template <class> class StoragePolicy = DefaultSPStorage
>
class SmartPtr:
	public StoragePolicy<T>
	, public OwnershipPolicy<typename StoragePolicy<T>::InitPointerType>
	, public CheckingPolicy<typename StoragePolicy<T>::StoredType>
	, public ConversionPolicy
{
	typedef StoragePolicy<T> 						SP;
	typedef OwnershipPolicy<typename StoragePolicy<T>::InitPointerType>	OP;
	typedef CheckingPolicy<typename StoragePolicy<T>::StoredType>		KP;
	typedef ConversionPolicy						CP;

	public:
		typedef typename SP::PointerType PointerType;
		typedef typename SP::StoredType StoredType;
		typedef typename SP::ReferenceType ReferenceType;

		typedef typename Select<OP::destructiveCopy,SmartPtr, const SmartPtr>::Result CopyArg;

		SmartPtr()
		{
			KP::OnDefault(GetImpl(*this));
		}

		explicit SmartPtr(ExplicitArg p) : SP(p)
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
		<typename T1
		, template <class> class OP1
		, class CP1
		, template <class> class KP1
		, template <class> class SP1>
		SmartPtr(const SmartPtr<T1, OP1, CP1, KP1, SP1):
			SP(rhs)
			, OP(rhs)
			, KP(rhs)
			, CP(rhs)
		{ GetImplRef(*this) = OP::Clone(GetImplRef(rhs)); }

		template
		<typename T1
		, template <class> class OP1
		, class CP1
		, template <class> class KP1
		, template <class> class SP1>
		SmartPtr(SmartPtr<T1, OP1, CP1, KP1, SP1):
			SP(rhs)
			, OP(rhs)
			, KP(rhs)
			, CP(rhs)
		{
			GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
		}

		SmartPtr& operator=(CopyArg& rhs)
		{
			SmartPtr temp(rhs);
			temp.Swap(*this);
			return *this;
		}
};


#endif /* !SMARTPTR_HPP */
