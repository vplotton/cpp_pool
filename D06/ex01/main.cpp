#include <iostream>
#include <cstdlib>
#include <string>

struct	Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

static int	last = 1;

char	*genRandom()
{
	static const	char	alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	char	*output = new char[8];

	srand ( time(NULL) * last );
	for (int i = 0; i < 8; ++i)
	{
		last = std::rand();
		output[i] = alphanum[last % (sizeof(alphanum) - 1)];
	}

	return (output);
}

void	*serialize()
{
	int		n;
	char	*s1;
	char	*s2;
	char	*number;
	char	*raw = new char[20];

	s1 = genRandom();
	
	srand ( time(NULL) * last );
	n = std::rand();

	s2 = genRandom();

	number = reinterpret_cast<char*>(&n);

	for (int i = 0 ; i < 20 ; ++i)
	{
		if (i < 8)
		{
			raw[i] = s1[i];
		}
		else if (i < 12)
		{
			raw[i] = number[i - 8];
		}
		else
		{
			raw[i] = s2[i - 12];
		}
	}

	delete s1;
	delete s2;

	return reinterpret_cast<void*>(raw);
}

Data	*deserialize(void *raw)
{
	Data		*data = new Data;
	std::string	tmp(reinterpret_cast<char*>(raw));

	data->s1 = tmp.substr(0, 8);
	data->s2 = tmp.substr(12, 20);
	data->n = *reinterpret_cast<int*>(const_cast<char*>(tmp.substr(8, 12).c_str()));

	return data;
}

int		main()
{
	void	*raw = serialize();

	std::string	tmp(reinterpret_cast<char*>(raw));

	std::cout << std::endl;
	std::cout << "Raw data - " << tmp << std::endl;

	Data	*data = deserialize(raw);

	std::cout << std::endl;

	std::cout << "Deserialized data" << std::endl;
	std::cout << "Data s1 - " << data->s1 << std::endl;
	std::cout << "Data n - " << data->n << std::endl;
	std::cout << "Data s2 - " << data->s2 << std::endl;

	std::cout << std::endl;

	return 0;
}
