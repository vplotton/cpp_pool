#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int		main()
{
	std::vector<int>	dataVec;

	dataVec.push_back(3);
	dataVec.push_back(4);
	dataVec.push_back(2);
	dataVec.push_back(1);

	std::cout << std::endl;
	std::cout << "==== [ Data Vector ] ====" << std::endl;
	std::cout << "Values: ";
	for (std::vector<int>::iterator it = dataVec.begin() ; it != dataVec.end() ; ++it)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	std::cout << "Find [3]: " <<  std::boolalpha << easyfind(dataVec, 3) << std::endl;
	std::cout << "Find [5]: " <<  std::boolalpha << easyfind(dataVec, 5) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::list<int>        dataList;

	dataList.push_back(3);
	dataList.push_back(4);
	dataList.push_back(2);
	dataList.push_back(1);

	std::cout << "==== [ Data List ] =====" << std::endl;
	std::cout << "Values: ";
	for (std::list<int>::iterator it = dataList.begin() ; it != dataList.end() ; ++it)
	{   
		std::cout << *it << "  ";
	}   
	std::cout << std::endl;

	std::cout << "Find [3]: " <<  std::boolalpha << easyfind(dataList, 3) << std::endl;
	std::cout << "Find [5]: " <<  std::boolalpha << easyfind(dataList, 5) << std::endl;
	std::cout << std::endl;

	return 0;
}
