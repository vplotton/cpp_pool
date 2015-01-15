#ifndef CTASSERT_HPP
# define CTASSERT_HPP

template <bool> struct CTAssert;
template<> struct CTAssert<true>
{
	CTAssert(...);
};

#endif /* !CTASSERT_HPP */
