#include <iostream>
#include "SmartPtr.hpp"

void	modInt(int *val)
{
	int	*newPtr = new int(0);
	val = newPtr;
	*val = 0;
}

void	modIntRef(int *&val)
{
	int	*newPtr = new int(0);
	val = newPtr;
	*val = 0;
}

int		main()
{
	int	*ptr = new int(5);
	int	*src = new int(7);
	int	*dest(NULL);
	SmartPtr<int>	*sp = new SmartPtr<int>(ptr);

	std::cout << "[ Normal ]\n";
	std::cout << "\tPointer: " << getImpl(*sp) << std::endl;
	std::cout << "\tValue: " << *getImpl(*sp) << std::endl;
	std::cout << std::endl;

	reset(*sp, src);
	std::cout << "[ Reset ]\n";
	std::cout << "\tPointer: " << getImpl(*sp) << "\n";
	std::cout << "\tValue: " << *getImpl(*sp) << std::endl;
	std::cout << std::endl;

	release(*sp, dest);
	std::cout << "[ Release ]\n";
	std::cout << "\tPointer: " << getImpl(*sp) << "\n";
	std::cout << "\tDest: " << dest << "\n";
	std::cout << "\tDest value: " << *dest << "\n";
	std::cout << std::endl;


	reset(*sp, dest);
	std::cout << "[ Create spCopy ]\n";
	SmartPtr<int>	*spCopy = new SmartPtr<int>(*sp);
	std::cout << "\tPointer sp: " << getImpl(*sp) << "\n";
	std::cout << "\tPointer spCopy: " << getImpl(*spCopy) << "\n";
	delete spCopy;
	std::cout << "[ delete spCopy ]\n";
	std::cout << "\tPointer sp: " << getImpl(*sp) << "\n";
	delete sp;
	std::cout << "[ delete sp ]\n";
	std::cout << "Is dest deleted? " << std::endl;
	*dest = 2;
	std::cout << *dest << std::endl;
}
