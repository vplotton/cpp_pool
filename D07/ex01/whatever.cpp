#include <iostream>

static int	count = 0;

template <typename T, typename U>
void	iter(T *& array, unsigned int size, U (*ft)(T &))
{
	for (unsigned int i = 0 ; i < size ; ++i)
	{
		ft(array[i]);
	}
}

void	ft_increment(int &a)
{
	++a;
}

template <typename T, typename U>
U	ft_decrement(T &a)
{
	if (count == 1)
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



int		main()
{
	int	*array = new int[10];
	std::cout << std::endl;
	for (int i = 0 ; i < 10 ; ++i)
	{
		array[i] = i;
		std::cout << "array[" << i << "] = " << array[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	iter<int, void>(array, 10, &ft_increment);

	std::cout << "[ TEST ] Iter ft_increment <int, void>" << std::endl;
	for (int i = 0 ; i < 10 ; ++i)
	{
		std::cout << "array[" << i << "] = " << array[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	


	float     *arrayFloat = new float[10];
	std::cout << std::endl;
	for (int i = 0 ; i < 10 ; ++i)
	{   
		arrayFloat[i] = static_cast<float>(i) / 2;
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "[ TEST ] Iter ft_decrement template <float, void>" << std::endl;
	iter<float, void>(arrayFloat, 10, &ft_decrement);
	for (int i = 0 ; i < 10 ; ++i)
	{   
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "[ TEST ] Iter ft_decrement template <float, float>" << std::endl;
	iter<float, float>(arrayFloat, 10, &ft_decrement);
	for (int i = 0 ; i < 10 ; ++i)
	{   
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;

}
