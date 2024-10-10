
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template <typename T>
int& easyfind(T array, int n)
{
	typename T::iterator it;
	it = std::find(array.begin(), array.end(), n);
	if (it != array.end())
		return (*it);
	throw std::logic_error("not inside");
}

#endif