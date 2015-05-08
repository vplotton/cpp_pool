#include <iostream>
#include "SmartPtr.hpp"

int		main()
{
	std::cout << "[ Create sp  ]\n";
	SmartPtr<int>	*sp = new SmartPtr<int>(new int (3));
	std::cout << "\tsp : " << sp  << "\n";
	std::cout << "\t**sp : " << **sp  << "\n";
	std::cout << "\tsp  pointer: " << SmartPtr<int>::GetPointer(*sp) << "\n";
	std::cout << std::endl;

	std::cout << "[ Create spCopy ]\n";
	SmartPtr<int>	*spCopy= new SmartPtr<int>(*sp);
	std::cout << "\tspCopy: " << spCopy << "\n";
	std::cout << "\t**spCopy: " << **spCopy << "\n";
	std::cout << "\tspCopy pointer: " << SmartPtr<int>::GetPointer(*sp) << "\n";
	std::cout << std::endl;

	std::cout << "[ Create spNeutral ]\n";
	SmartPtr<int>	*spNeutral = new SmartPtr<int>();
	std::cout << "\tdelete initial value: ";
	*spNeutral = *sp;
	std::cout << "\tspNeutral: " << spNeutral << "\n";
	std::cout << "\t**spNeutral: " << **spNeutral << "\n";
	std::cout << "\tspNeutral pointer: " << SmartPtr<int>::GetPointer(*spNeutral) << "\n";
	std::cout << std::endl;
	
	std::cout << "[ Create spSwap ]\n";
	SmartPtr<int>	*spSwap= new SmartPtr<int>(new int(5));
	std::cout << "\tspSwap: " << spSwap<< "\n";
	std::cout << "\t**spSwap: " << **spSwap<< "\n";
	std::cout << "\tspSwap pointer: " << SmartPtr<int>::GetPointer(*spSwap) << "\n";
	std::cout << std::endl;

	std::cout << "[ Swap value spSwap <-> sp ]\n";
	spSwap->Swap(*sp);
	std::cout << "\tsp : " << sp  << "\n";
	std::cout << "\t**sp : " << **sp  << "\n";
	std::cout << "\tsp  pointer: " << SmartPtr<int>::GetPointer(*sp) << "\n";
	std::cout << "\t=== === ===\n";
	std::cout << "\tspSwap: " << spSwap<< "\n";
	std::cout << "\t**spSwap: " << **spSwap<< "\n";
	std::cout << "\tspSwap pointer: " << SmartPtr<int>::GetPointer(*spSwap) << "\n";
	std::cout << std::endl;

	std::cout << "[ Reset sp value ]\n";
	std::cout << "\tdelete old sp: ";
	sp->Reset(*sp, new int(8));
	std::cout << "\tsp : " << sp  << "\n";
	std::cout << "\t**sp : " << **sp  << "\n";
	std::cout << "\tsp  pointer: " << SmartPtr<int>::GetPointer(*sp) << "\n";
	std::cout << std::endl;

	std::cout << "[ Test operators ]\n";
	std::cout << "\t[     test     ] - [ exp ]: [ result ]\n";
	std::cout << std::boolalpha << "\t *sp == *spSwap  -  false :   " << (*sp == *spSwap) << std::endl;
	std::cout << std::boolalpha << "\t *sp != *spSwap  -  true  :   " << (*sp != *spSwap) << std::endl;
	std::cout << std::boolalpha << "\t *sp > *spSwap   -  true  :   " << (*sp > *spSwap) << std::endl;
	std::cout << std::boolalpha << "\t *sp < *spSwap   -  false :   " << (*sp < *spSwap) << std::endl;
	std::cout << std::boolalpha << "\t *sp >= *spSwap  -  true  :   " << (*sp >= *spSwap) << std::endl;
	std::cout << std::boolalpha << "\t *sp <= *spSwap  -  false :   " << (*sp <= *spSwap) << std::endl;
	std::cout << std::endl;

	std::cout << "[ Delete every smartPtr ]\n";
	std::cout << "\tdelete sp: ";
	delete sp;
	std::cout << "\tdelete spSwap [now original sp ]:\n";
	delete spSwap;
	std::cout << "\tdelete spCopy [ original sp copy ] :\n";
	delete spCopy;
	std::cout << "\tdelete spNeutral [ original sp assignement ] : ";
	delete spNeutral;
}
