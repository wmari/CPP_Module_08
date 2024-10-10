#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	int	i;

	{
		std::vector<int>	vector;

		for (i = 0; i < 10; ++i)
			vector.push_back(i);
		std::cout << easyfind< std::vector<int> >(vector, 4)<< std::endl;
		for (i = 0; i < 10; ++i)
			std::cout << vector[i] << " ";
		std::cout << std::endl;
	}
	{
		std::list<int>				list;
		std::list<int>::iterator	it;

		for (i = 0; i < 10; ++i)
			list.push_back(i);
		std::cout << easyfind< std::list<int> >(list, 9) << std::endl;
		for (it = list.begin(); it != list.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			easyfind< std::list<int> >(list, 20);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}