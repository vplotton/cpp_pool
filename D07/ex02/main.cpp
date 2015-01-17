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

	std::cout << "==== Array Of 3 <int> ====" << std::endl;
	Array<int>	size3Array(3);
	std::cout << "size: " << size3Array.size() << std::endl;
	std::cout << "Array[0] = " << size3Array[0] << std::endl;
	std::cout << "Array[3] = ";
	try
	{
		std::cout << size3Array[3];
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Set Array[2] = 2" << std::endl;
	size3Array[2] = 2;
	for (unsigned int i = 0 ; i < size3Array.size() ; ++i)
	{
		std::cout << "size3Array[" << i << "] = " << size3Array[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "==== Copy Of size3Array <int> ====" << std::endl;
	Array<int>   size3CopyArray(size3Array);
	std::cout << "size: " << size3CopyArray.size() << std::endl;
	std::cout << "Array[0] = " << size3CopyArray[0] << std::endl;
	std::cout << "Array[3] = ";
	try 
	{   
		std::cout << size3CopyArray[3];
	}   
	catch (std::out_of_range &e) 
	{   
		std::cerr << e.what() << std::endl;
	} 
	for (unsigned int i = 0 ; i < size3CopyArray.size() ; ++i)
	{
		std::cout << "size3CopyArray[" << i << "] = " << size3CopyArray[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "==== StringArray <std::string> ====" << std::endl;
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
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "==== intPointerArray <int*> ====" << std::endl;
	Array<int*>  intPointerArray(3);
	std::cout << "size: " << intPointerArray.size() << std::endl;
	int		intTab[3];
	intTab[0] = 1;
	intTab[1] = 2;
	intTab[2] = 3;
	intPointerArray[0] = &intTab[0];
	intPointerArray[1] = &intTab[1];
	intPointerArray[2] = &intTab[2];
	for (unsigned int i = 0 ; i < intPointerArray.size() ; ++i)
	{
		std::cout << "intPointerArray[" << i << "] = " << intPointerArray[i]
			<< std::endl;
	}
	std::cout << "intPointerArray[10] = ";
	try
	{
		std::cout << intPointerArray[10];
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== arrayArray <Array<std::string> > ====" << std::endl;
	Array<Array<std::string> >  arrayArray(1);
	arrayArray[0] = stringArray;
	std::cout << "Set arrayArray[0] = stringArray" << std::endl;
	std::cout << "size: " << arrayArray.size() << std::endl;
	for (unsigned int i = 0 ; i < arrayArray[0].size() ; ++i)
	{
		std::cout << "arrayArray[0][" << i << "] = "
			<< arrayArray[0][i] << std::endl;
	}
	std::cout << "arrayArray[1] = ";
	try
	{
		arrayArray[1] = stringArray;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif
	return 0;
}
