#include <iostream>

template <typename T>
void	iter(T *& array, unsigned int size, void (*ft)(T &))
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

template <typename T>
void	ft_decrement(T &a)
{
	--a;
}
template void ft_decrement<float>(float & a);


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

	iter<int>(array, 10, &ft_increment);

	std::cout << "[ TEST ] Iter ft_increment <int>" << std::endl;
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

	iter<float>(arrayFloat, 10, &ft_decrement);

	std::cout << "[ TEST ] Iter ft_decrement template <float>" << std::endl;
	for (int i = 0 ; i < 10 ; ++i)
	{   
		std::cout << "array[" << i << "] = " << arrayFloat[i] << "  ";
	}   
	std::cout << std::endl;
	std::cout << std::endl;

}
