#include <iostream>

template <unsigned long n>
struct Factorial
{
	static const unsigned long result = n * Factorial<n - 1>::result;
};

template <>
struct Factorial <0>
{
	static const unsigned long result = 1;
};
/*
template <unsigned long n>
struct FactorialTab
{
	static const unsigned long result = Factorial<n>::result;
};
*/
int		main()
{
	std::cout << Factorial<4>::result << std::endl;
	return 0;
}
