#ifndef SMARTPTR_HPP
# define SMARTPTR_HPP

# include <cassert>

/* === STORAGE POLICY === */
template <class T>
class SPDefaultStorage
{
	public:
		typedef T*	StoredType;
		typedef T*	PointerType;
		typedef T*	InitPointerType;
		typedef T&	ReferenceType;

		SPDefaultStorage(): m_pointer(Default()) {}
		SPDefaultStorage(const SPDefaultStorage &): m_pointer(0) {}
		template <class U>
		SPDefaultStorage(const SPDefaultStorage<U> &): m_pointer(0) {}
		SPDefaultStorage(const StoredType &p): m_pointer(p) {}

		PointerType	operator->() const { return m_pointer; }
		ReferenceType	operator*() const { return *m_pointer; }

		void		Swap(SPDefaultStorage &rhs)
		{ std::swap(m_pointer, rhs.m_pointer); }

		/* Accessor */
		template <class F>
		friend typename SPDefaultStorage<F>::PointerType	GetImpl(const SPDefaultStorage<F> &sp);
		template <class F>
		friend typename SPDefaultStorage<F>::StoredType		&GetImplRef(const SPDefaultStorage<F> &sp);
		template <class F>
		friend typename SPDefaultStorage<F>::StoredType		&GetImplRef(SPDefaultStorage<F> &sp);

	protected:
		/* Destroyer ^_^ */
		void	Destroy() { delete m_pointer; }
		/* default pointer definition */
		static StoredType	Default() { return 0; }
		
	private:
		/* data */
		StoredType	m_pointer;
};
template <class F>
inline typename SPDefaultStorage<F>::PointerType	GetImpl(const SPDefaultStorage<F> &sp)
{ return sp.m_pointer; }

template <class F>
inline typename SPDefaultStorage<F>::StoredType		&GetImplRef(const SPDefaultStorage<F> &sp)
{ return sp.m_pointer; }

template <class F>
inline typename SPDefaultStorage<F>::StoredType		&GetImplRef(SPDefaultStorage<F> &sp)
{ return sp.m_pointer; }

/* === OWNERSHIP POLICY === */
template <class P>
class SPRefCounterOwnership
{
	public:
		SPRefCounterOwnership(): m_count(new unsigned int(1))
		{
			assert(m_count != 0);
			*m_count = 1;
		}
		SPRefCounterOwnership(const SPRefCounterOwnership &rhs): m_count(rhs.m_count) {}
		template <typename P1>
		SPRefCounterOwnership(const SPRefCounterOwnership<P1> &rhs):
			m_count(reinterpret_cast<const SPRefCounterOwnership &>(rhs).m_count)
		{}

		P	Clone(const P &val)
		{
			++*m_count;
			return val;
		}
		bool	Release(const P &)
		{
			if (!--*m_count)
			{
				delete m_count;
				m_count = NULL;
				return true;
			}
			return false;
		}

		void	Swap(SPRefCounterOwnership &rhs)
		{ std::swap(m_count, rhs.m_count); }

		enum { destructiveCopy = false };

	private:
		/* Data */
		unsigned int	*m_count;
};

/* === CONVERSION POLICY === */
struct SPAllowConversion
{
	enum { allow = true };
	void Swap(SPAllowConversion&) {}
};

struct SPDisallowConversion
{
	SPDisallowConversion() {}
	SPDisallowConversion(const SPAllowConversion &) {}

	enum { allow = false };
	void Swap(SPDisallowConversion &) {}
};

/* === CHECKING POLICY === */
template <class N>
struct SPNoChecking
{
	SPNoChecking() {}
	template <class N1>
	SPNoChecking(const SPNoChecking<N1> &) {}

	static void	OnDereference(const N &) {}
	static void	OnDefault(const N &) {}
	static void	OnInit(const N &) {}
	static void	Swap(SPNoChecking &) {}
};

template <class N>
struct SPAssertChecking
{
	SPAssertChecking() {}
	template <class N1>
	SPAssertChecking(const SPAssertChecking<N1> &) {}
	template <class N1>
	SPAssertChecking(const SPNoChecking<N1> &) {}

	static void	OnDereference(const N val)
	{ assert(val); static_cast<void>(val); }
	static void	OnDefault(const N &) {}
	static void	OnInit(const N &) {}
	static void	Swap(SPAssertChecking &) {}
};

template <class N>
struct SPAssertStrictChecking
{
	SPAssertStrictChecking() {}
	template <class N1>
	SPAssertStrictChecking(const SPAssertStrictChecking<N1> &) {}
	template <class U>
	SPAssertStrictChecking(const SPAssertChecking<U> &) {}
	template <class V>
	SPAssertStrictChecking(const SPNoChecking<V> &) {}

	static void	OnDereference(const N val)
	{ assert(val); }
	static void	OnDefault(const N val)
	{ assert(val); }
	static void	OnInit(const N val)
	{ assert(val); }
	static void	Swap(SPAssertStrictChecking &) {}
};


/* Helper: if flag == true => result == T else result == U */
template <bool flag, typename T, typename U>
struct Select
{   
	typedef T Result;
};  
template <typename T, typename U>
struct Select<false, T, U>
{   
	typedef U Result;
};

/* === \\ SMARTPTR // === */
template <typename T,
	 template <class> class OwnershipPolicy = SPRefCounterOwnership,
	 class ConversionPolicy = SPAllowConversion,
	 template <class> class CheckingPolicy = SPNoChecking,
	 template <class> class StoragePolicy = SPDefaultStorage>
	 class SmartPtr;

template <typename T,
	template <class> class OwnershipPolicy = SPRefCounterOwnership,
	class ConversionPolicy = SPAllowConversion,
	template <class> class CheckingPolicy = SPNoChecking,
	template <class> class StoragePolicy = SPDefaultStorage>
struct SmartPtrDef
{
	typedef SmartPtr<T
		, OwnershipPolicy
		, ConversionPolicy
		, CheckingPolicy
		, StoragePolicy> type;
};

template <typename T,
	template <class> class OwnershipPolicy,
	class ConversionPolicy,
	template <class> class CheckingPolicy,
	template <class> class StoragePolicy>
class SmartPtr:
	public StoragePolicy<T>
	, public OwnershipPolicy<typename StoragePolicy<T>::InitPointerType>
	, public CheckingPolicy<typename StoragePolicy<T>::StoredType>
	, public ConversionPolicy
{
	/* *** TYPEDEFS *** */
	private:
		typedef OwnershipPolicy<typename StoragePolicy<T>::InitPointerType>	OP;
		typedef CheckingPolicy<typename StoragePolicy<T>::StoredType>		KP;
		typedef ConversionPolicy						CP;
		typedef StoragePolicy<T>						SP;

	public:
		typedef typename SP::ReferenceType const	ConstReferenceType;
		typedef typename SP::PointerType const		ConstPointerType;
		typedef typename SP::ReferenceType	ReferenceType;
		typedef typename SP::PointerType	PointerType;
		typedef typename SP::StoredType		StoredType;

		typedef typename Select<OP::destructiveCopy, SmartPtr, const SmartPtr>::Result	CopyArg;
	private:
		struct NeverMatched {};
		typedef typename Select<!CP::allow, const StoredType&, NeverMatched>::Result	ExplicitArg;
		typedef typename Select< CP::allow, const StoredType&, NeverMatched>::Result	ImplicitArg;
	public:
		/*  *** CONSTRUCTORS *** */
		/* Normal constructors */
		SmartPtr()
		{
			KP::OnDefault(GetImpl(*this));
		}
		explicit SmartPtr(ExplicitArg p): SP(p)
		{
			KP::OnInit(GetImpl(*this));
		}
		SmartPtr(ImplicitArg p): SP(p)
		{
			KP::OnInit(GetImpl(*this));
		}
		SmartPtr(CopyArg &rhs): SP(rhs), OP(rhs), KP(rhs), CP(rhs)
		{
			GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
		}
		/* Conversion constructors */
		template <typename T1,
			template <class> class OP1, 
			class CP1, 
			template <class> class KP1, 
			template <class> class SP1>
		SmartPtr(const SmartPtr<T1, OP1, CP1, KP1, SP1 > &rhs):
			SP(rhs), OP(rhs), KP(rhs), CP(rhs)
		{
			GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
		}
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		SmartPtr(SmartPtr<T1, OP1, CP1, KP1, SP1 > &rhs):
			SP(rhs), OP(rhs), KP(rhs), CP(rhs)
		{
			GetImplRef(*this) = OP::Clone(GetImplRef(rhs));
		}

		/* Destructor */
	        ~SmartPtr()
	        {
			if (OP::Release(GetImpl(*static_cast<SP*>(this))))
			{
				std::cout << "Destructed\n";
				SP::Destroy();
			}
		}

		/* *** OPERATORS *** */
		/* assignation */
		SmartPtr& operator=(CopyArg& rhs)
		{
			SmartPtr temp(rhs);
			temp.Swap(*this);
			return *this;
		}
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		SmartPtr& operator=(const SmartPtr<T1, OP1, CP1, KP1, SP1 > &rhs)
		{
			SmartPtr temp(rhs);
			temp.Swap(*this);
			return *this;
		}
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		SmartPtr& operator=(SmartPtr<T1, OP1, CP1, KP1, SP1 > &rhs)
		{
			SmartPtr temp(rhs);
			temp.Swap(*this);
			return *this;
		}

		/* Dereference operator -> (access) */
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

		/* Dereference operator * (value) */
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

		/* To enable if (!sp) statement */
		bool operator!() const { return GetImpl(*this) == 0; }

		/* Ambiguity Busters */
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
	        bool operator==(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return GetImpl(*this) == GetImpl(rhs); } /* equality */

		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		bool operator!=(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return !(*this == rhs); } /* difference */

		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		bool operator<(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return GetImpl(*this) < GetImpl(rhs); } /* inferior */

		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		bool operator>(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return GetImpl(*this) > GetImpl(rhs); } /* superior */

		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		bool operator<=(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return !(GetImpl(*this) > GetImpl(rhs)); } /* inferior or equal */

		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		bool operator>=(const SmartPtr<T1, OP1, CP1, KP1, SP1 >& rhs) const
	        { return !(GetImpl(*this) < GetImpl(rhs)); } /* superior or equal */

		/* To enable if (sp) */
	private:
		struct Tester
		{
			Tester(int) {}
			void dummy() {}
		};

		typedef void (Tester::*unspecified_boolean_type_)();
		typedef typename Select<CP::allow, Tester, unspecified_boolean_type_>::Result
				unspecified_boolean_type;
	public:
		/* enable if (sp) */
		operator unspecified_boolean_type() const
		{
			return !*this ? 0 : &Tester::dummy;
		}

		/* *** MEtHODS *** */
		/* Swap */
		void Swap(SmartPtr& rhs)
		{
			OP::Swap(rhs);
			CP::Swap(rhs);
			KP::Swap(rhs);
			SP::Swap(rhs);
		}

		/* Release */
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		friend void Release(SmartPtr<T1, OP1, CP1, KP1, SP1> &sp, typename SP1<T1>::StoredType& p);

		/* Reset */
		template <typename T1,
			template <class> class OP1,
			class CP1,
			template <class> class KP1,
			template <class> class SP1>
		inline void Reset(SmartPtr<T1, OP1, CP1, KP1, SP1> &sp, typename SP1<T1>::StoredType p)
		{
			SmartPtr<T1, OP1, CP1, KP1, SP1>(p).Swap(sp);
		}
		/* Get Pointer */
		static inline T *GetPointer(const SmartPtr &sp)
	        { return GetImpl( sp ); }
};

/* *** SMARTPTR FRIENDS *** */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP>
inline void Release(SmartPtr<T, OP, CP, KP, SP> &sp,
		typename SP<T>::StoredType& p)
{
	p = GetImplRef(sp);
	GetImplRef(sp) = SP<T>::Default();
}

/*
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP>
inline void Reset(SmartPtr<T, OP, CP, KP, SP> &sp,
		typename SP<T>::StoredType p)
{
	SmartPtr<T, OP, CP, KP, SP>(p).Swap(sp);
}
*/

/* *** SMARTPTR ADDITIONAL OPERATORS *** */
/* operator== for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator==(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return GetImpl(lhs) == rhs;
}

/* operator== for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator==(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return rhs == lhs;
}

/* operator!= for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator!=(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return !(lhs == rhs);
}
/* operator!= for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator!=(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return rhs != lhs;
}

/* operator< for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator<(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return (GetImpl( lhs ) < rhs);
}

/* operator< for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator<(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return (GetImpl( rhs ) < lhs);
}

/* operator> for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator>(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return rhs < lhs;
}

/* operator> for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator>(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return rhs < lhs;
}

/* operator<= for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator<=(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return !(rhs < lhs);
}

/* operator<= for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator<=(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return !(rhs < lhs);
}

/* operator>= for lhs = SmartPtr, rhs = raw pointer */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator>=(const SmartPtr<T, OP, CP, KP, SP> &lhs, U *rhs)
{
	return !(lhs < rhs);;
}

/* operator>= for lhs = raw pointer, rhs = SmartPtr */
template <typename T,
	template <class> class OP,
	class CP,
	template <class> class KP,
	template <class> class SP,
	typename U>
inline bool operator>=(U* lhs, const SmartPtr<T, OP, CP, KP, SP> &rhs)
{
	return !(lhs < rhs);;
}
#endif /* !SMARTPTR_HPP */
