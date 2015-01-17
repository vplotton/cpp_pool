#ifdef _TEST_INLINE
# include "InlineArray.hpp"
#elif _TEST_NO_INLINE
# include "NoInlineArray.hpp"
#else
# include "Array.hpp"
#endif

#include <iostream>
#include <string>

int		main()
{
#ifdef _TEST_INLINE
	std::cout << "==== [ INLINE TEST ] ====" << std::endl;
#elif _TEST_NO_INLINE
	std::cout << "==== [ NO INLINE TEST ] ====" << std::endl;
#endif

#if defined _TEST_INLINE || defined _TEST_NO_INLINE
	unsigned int	reps = 10000;
	unsigned int	size = 100000;
	for (unsigned int i = 0 ; i < reps ; ++i)
	{
			Array<int>	*array = new Array<int>(size);
			for (unsigned int j = 0 ; j < size ; ++j)
			{
				(*array)[j] = j;
			}
		try
		{
			delete array;
		}
		catch (...)
		{
			std::cerr <<  "Critical error" << std::endl;
		}
	}
#else
	std::cout << std::endl;
	std::cout << "==== EMPTY ====" << std::endl;
	Array<int>	*emptyArray = new Array<int>();

	std::cout << "size: " << emptyArray->size() << std::endl;
	std::cout << "emptyArray[0] = ";
	try
	{
		std::cout << "emptyArray[0]: " << (*emptyArray)[0] << std::endl;
	}   
	catch (std::out_of_range &e) 
	{   
		std::cerr << e.what() << std::endl;
	}  

	delete emptyArray;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== Array Of 10 int ====" << std::endl;
	Array<int>	size10Array(10);
	std::cout << "size: " << size10Array.size() << std::endl;
	std::cout << "Array[0] = " << size10Array[0] << std::endl;
	std::cout << "Array[10] = ";
	try
	{
		std::cout << size10Array[10];
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Array[5] = 5" << std::endl;
	size10Array[5] = 5;
	for (unsigned int i = 0 ; i < size10Array.size() ; ++i)
	{
		std::cout << "size10Array[" << i << "] = " << size10Array[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "==== Copy Of size10Array int ====" << std::endl;
	Array<int>   size10CopyArray(size10Array);
	std::cout << "size: " << size10CopyArray.size() << std::endl;
	std::cout << "Array[0] = " << size10CopyArray[0] << std::endl;
	std::cout << "Array[10] = ";
	try 
	{   
		std::cout << size10CopyArray[10];
	}   
	catch (std::out_of_range &e) 
	{   
		std::cerr << e.what() << std::endl;
	} 
	for (unsigned int i = 0 ; i < size10CopyArray.size() ; ++i)
	{
		std::cout << "size10CopyArray[" << i << "] = " << size10CopyArray[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "==== StringArray int ====" << std::endl;
	Array<std::string>	stringArray(3);
	std::cout << "size: " << stringArray.size() << std::endl;
	stringArray[0] = "blabla";
	stringArray[1] = "blibli";
	stringArray[2] = "bloblo";
	for (unsigned int i = 0 ; i < stringArray.size() ; ++i)
	{   
		std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
	}
	std::cout << "stringArray[10] = ";
	try 
	{   
		std::cout << stringArray[10];
	}   
	catch (std::out_of_range &e) 
	{   
		std::cerr << e.what() << std::endl;
	} 
#endif
	return 0;
}
