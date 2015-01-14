#include <iostream>

static int	count = 0;

template <typename T, typename U>
void	iter(T * const & array, unsigned int size, U (*ft)(T &))
{
	for (unsigned int i = 0 ; i < size ; ++i)
	{
		ft(array[i]);
	}
}

void	ft_increment(int &a)
{
	if (count == 0)
	{
		std::cout << "void ft_increment(int &a);" << std::endl;
		count++;
	}
	++a;
}

	template <typename T, typename U>
U	ft_decrement(T &a)
{
	if (count == 0)
	{
		std::cout << "U ft_decrement(T &a);" << std::endl;
		count++;
	}
	--a;
	return (a);
}


	template <typename T>
void	ft_decrement(T &a)
{
	if (count == 0)
	{
		std::cout << "void ft_decrement(T &a);" << std::endl;
		count++;
	}
	--a;
}
template float ft_decrement<float, float>(float & a);

std::string	ft_reverse(std::string & s)
{
	if (count == 0)
	{
		std::cout << "std::string ft_reverse(std::string & s)" << std::endl;
		count++;
	}

	std::string copy(s);
	for (unsigned int i = 0 ; i < s.size() ; ++i)
	{
		s.at(i) = copy.at(s.size() - i - 1);
	}
	return s;
}


int		main()
{
	int	*array = new int[3];
	std::cout << std::endl;
	std::cout << "[ TEST ] Iter ft_increment <int, void>" << std::endl;
	for (int i = 0 ; i < 3 ; ++i)
	{
		array[i] = i;
		std::cout << "array[" << i << "] = " << array[i] << "  ";
	}
	std::cout << std::endl;

	iter<int, void>(array, 3, &ft_increment);

	for (int i = 0 ; i < 3 ; ++i)
	{
		std::cout << "array[" << i << "] = " << array[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	count = 0;
	std::cout << "[ TEST ] Iter ft_decrement template <float, void>" << std::endl;
	float     *arrayFloat = new float[10];
	for (int i = 0 ; i < 3 ; ++i)
	{   
		arrayFloat[i] = static_cast<float>(i) / 2;
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;

	iter<float, void>(arrayFloat, 3, &ft_decrement);
	for (int i = 0 ; i < 3 ; ++i)
	{   
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	count = 0;
	std::cout << "[ TEST ] Iter ft_decrement template <float, float>" << std::endl;
	for (int i = 0 ; i < 3 ; ++i)
	{
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}
	std::cout << std::endl;
	iter<float, float>(arrayFloat, 3, &ft_decrement);
	for (int i = 0 ; i < 3 ; ++i)
	{   
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	count = 0;
	std::cout << "[ TEST ] Iter ft_reverse template <std::string, std::string>"	<< std::endl;
	std::string	*arrayString = new std::string[3];
	arrayString[0] = "blabla";
	arrayString[1] = "blibli";
	arrayString[2] = "bloblo";
	for (int i = 0 ; i < 3 ; ++i)
	{
		std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
	}

	iter<std::string, std::string>(arrayString, 3, &ft_reverse);
	for (int i = 0 ; i < 3 ; ++i)
	{
		std::cout << "array[" << i << "] = " << arrayString[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
