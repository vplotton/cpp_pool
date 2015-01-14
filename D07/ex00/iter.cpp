#include <iostream>

template <typename T>
void	swap(T & val1, T & val2)
{
	T	tmp;

	tmp = val1;
	val1 = val2;
	val2 = tmp;
}

template <typename T>
T const & min(T const & val1, T const & val2)
{
	return (val1 < val2 ? val1 : val2);
}

template <typename T>
T const & max(T const & val1, T const & val2)
{
	return (val1 > val2 ? val1 : val2);
}

int		main()
{
	int	intA = 1;
	int	intB = 9;
	float	floatA = 4.2;
	float	floatB = 8.2;

	std::cout << "==== Test Swap ===" << std::endl;
	std::cout << "[ TEST ] intA == " << intA << " && intB == " << intB << std::endl;
	swap<int>(intA, intB);
	std::cout << "intA == " << intA << std::endl;
	std::cout << "intB == " << intB << std::endl;
	std::cout << std::endl;

	std::cout << "[ TEST ] floatA == " << floatA << " && floatB == " << floatB << std::endl;
	swap<float>(floatA, floatB);
	std::cout << "floatA == " << floatA << std::endl;
	std::cout << "floatB == " << floatB << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== Test Min ===" << std::endl;
	std::cout << "[ TEST ] intA == " << intA << " && intB == " << intB << std::endl;
	std::cout << "Min value: " << min<int>(intA, intB) << std::endl;
	std::cout << std::endl;

	int	intC = 1;
	int	intD = 1;
	std::cout << "[ TEST ] intC == " << intC << " && intD == " << intD << std::endl;
	std::cout << "Min value: " << min<int>(intC, intD) << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST ] floatA == " << floatA << " && floatB == " << floatB << std::endl;
	std::cout << "Min value: " << min<float>(floatA, floatB) << std::endl;
	std::cout << std::endl;
	
	float     floatC = 1;
	float     floatD = 1;
	std::cout << "[ TEST ] floatC == " << floatC << " && floatD == " << floatD << std::endl;
	std::cout << "Min value: " << min<float>(floatC, floatD) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== Test Max ===" << std::endl;
	std::cout << "[ TEST ] intA == " << intA << " && intB == " << intB << std::endl;
	std::cout << "Max value: " << max<int>(intA, intB) << std::endl;
	std::cout << std::endl;

	std::cout << "[ TEST ] intC == " << intC << " && intD == " << intD << std::endl;
	std::cout << "Max value: " << max<int>(intC, intD) << std::endl;
	std::cout << std::endl;

	std::cout << "[ TEST ] floatA == " << floatA << " && floatB == " << floatB << std::endl;
	std::cout << "Max value: " << max<float>(floatA, floatB) << std::endl;
	std::cout << std::endl;

	std::cout << "[ TEST ] floatC == " << floatC << " && floatD == " << floatD << std::endl;
	std::cout << "Max value: " << max<float>(floatC, floatD) << std::endl;
	std::cout << std::endl;
}
