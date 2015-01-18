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
	if (_type == 1 || _type == 2)
	{
		_box =  newwin(_len / 2, _len, startY, startX);
		startX  = startX + _len;
		totalLen += _len;
		/*
		 *		IMplementer ici la gestion sur 2 ligne
		 *
		 */
		box(_box, 0 , 0);
//		std::cerr << " len : " << _len << "startx = " << startX << std::endl;

	}
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

void	Box::setText(std::string title, std::string txt)
{
	_info.insert(std::make_pair(title, txt));
}

std::map<std::string , std::string>  Box::getMapInfo()
{
		return (_info);
}
