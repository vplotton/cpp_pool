#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool	easyfind(T & data, int const & valueToFound)
{
	if (std::find(data.begin(), data.end(), valueToFound) != data.end())
	{
		return true;
	}
	return false;
}

#endif /* !EASYFIND_HPP */
