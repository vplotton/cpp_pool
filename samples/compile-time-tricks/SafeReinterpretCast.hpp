#ifndef SAFEREINTERPRETCAST_HPP
# define SAFEREINTERPRETCAST_HPP

# include "CTAssert.hpp"

# define STATIC_CHECK(expr, msg) \
{ \
	class ERROR_##msg {}; \
	(void)sizeof(CTAssert<(expr) != 0>((ERROR_##msg())));\
}

template <typename To, typename From>
To	safeReinterpretCast(From from)
{
	STATIC_CHECK(sizeof(From) < sizeof(To), Destination_Type_Too_Narrow);
	return reinterpret_cast<To>(from);
}

#endif /* !SAFEREINTERPRETCAST_HPP */
