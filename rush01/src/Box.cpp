#include "Box.hpp"

int Box::totalLen = 0;
int	Box::startX = 0;
int Box::startY = 0;

Box::Box()
{
}

Box::Box(int ptype, int  plen)
	:  _len(plen), _type(ptype)
{
//	if (_type == 1)
//	{
		_box =  newwin(_len / 2, _len, startY, startX);
		_x = startX;
		_y = startY;
		startX  = startX + _len;
		totalLen += _len;
		box(_box, 0 , 0);
//	}
}
Box::Box(Box const & src)
{
	*this = src;
}

Box::~Box()
{
}

Box & Box::operator=(Box const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}


WINDOW * Box::getWinBox()
{
	return (_box);
}

//#include <fstream>

void	Box::setText(std::string title, std::string txt)
{
//	std::ofstream file;
//	file.open ("test.txt", fstream::in | fstream::out | fstream::app);
	_info.insert(std::make_pair(title, txt));
//	file << _info.first;
//	file.close();
}

std::map<std::string , std::string>  Box::getMapInfo()
{
		return (_info);
}


int Box::getX()
{
	return _x;
}

int Box::getY()
{
	return _y;
}
