#ifndef SPTRSTORAGE_HPP
# define SPTRSTORAGE_HPP

#include <iostream>

template <class T>
class SPtrStorage
{
	protected:
		typedef T*	StoredType;
		typedef T*	PointerType;
		typedef T&	ReferenceType;

	public:
		SPtrStorage(): m_pointee(Default()) {}

		SPtrStorage(StoredType const & p): m_pointee(p) {}

		PointerType	operator->() const
		{ return m_pointee; }

		ReferenceType	operator*() const
		{ return *m_pointee; }

		template <class F>
		friend typename SPtrStorage<F>::PointerType GetImpl(const SPtrStorage<F>& sp); 

		template <class F>
		friend const typename SPtrStorage<F>::StoredType& GetImplRef(const SPtrStorage<F>& sp); 

		template <class F>
		friend typename SPtrStorage<F>::StoredType& GetImplRef(SPtrStorage<F>& sp); 

	protected:
		void	destroy()
		{ delete m_pointee; }

		static StoredType	Default()
		{ return 0; }

	private:
		StoredType	m_pointee;
};

template <class T>
inline typename SPtrStorage<T>::PointerType GetImpl(const SPtrStorage<T>& sp)
{ return sp.pointee_; }

template <class T>
inline const typename SPtrStorage<T>::StoredType& GetImplRef(const SPtrStorage<T>& sp)
{ return sp.pointee_; }

template <class T>
inline typename SPtrStorage<T>::StoredType& GetImplRef(SPtrStorage<T>& sp)
{ return sp.pointee_; }

template<class T> T*	getImpl(SPtrStorage<T> &sp)
{
	return sp.pointee();
}

template<class T> T*	&getImplRef(SPtrStorage<T> &sp)
{
	return sp.pointeeRef();
}

template<class T> void	reset(SPtrStorage<T> &sp, T *source)
{
	delete sp.pointeeRef();
	sp.pointee(source);
}

template<class T> void release(SPtrStorage<T> &sp, T *&destination)
{
	destination = sp.pointeeRef();
	sp.pointee(NULL);
}

#endif /* !SPTRSTORAGE_HPP */
