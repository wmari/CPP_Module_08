#include "Span.hpp"

Span::Span() : _length(0), _fill(0)
{
	return ;
}

Span::Span(unsigned int n) : _length(n), _fill(0)
{
	return ;
}

Span::Span(const Span &copy) : _vec(copy._vec), _length(copy._length), _fill(copy._fill)
{
	return ;
}

Span &Span::operator=(Span const &copy)
{
	if (this == &copy)
		return *this;
	this->_vec = copy._vec;
	this->_length = copy._length;
	this->_fill = copy._fill;
	return *this;
}

void Span::addNumber(int n)
{
	if (_fill == _length)
		throw NotEnoughSpace();
	_vec.push_back(n);
	_fill++;
}

void Span::addNumber(std::vector<int> range)
{
	if (_fill + range.size() > _length)
		throw NotEnoughSpace();
	_vec.insert(_vec.end(), range.begin(), range.end());
	_fill += range.size();
}

void Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end)
{
	for (; it_begin != it_end; it_begin++)
	{
		if (_fill == _length)
			throw NotEnoughSpace();
		_vec.push_back(*it_begin);
		_fill++;
	}
}

unsigned int Span::shortestSpan()
{
	if (_fill <= 1)
		throw NotEnoughMember();
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	int	inter = -1;
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		for (it2 = it; it2 != _vec.end(); it2++)
		{
			if (it2 != it && inter < 0)
				inter = std::abs(*it2 - *it);
			else if (it2 != it && inter > std::abs(*it2 - *it))
				inter = std::abs(*it2 - *it);
		}
	}
	return (inter);
}

unsigned int Span::longestSpan()
{
	if (_fill <= 1)
		throw NotEnoughMember();
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	int	inter = -1;
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		for (it2 = it; it2 != _vec.end(); it2++)
		{
			if (it2 != it && inter < 0)
				inter = std::abs(*it2 - *it);
			else if (it2 != it && inter < std::abs(*it2 - *it))
				inter = std::abs(*it2 - *it);
		}
	}
	return (inter);
}

unsigned int	Span::getLength()
{
	return _length;
}

unsigned int	Span::getFill()
{
	return _fill;
}

Span::~Span()
{
	return ;
}