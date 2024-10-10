#include "Span.hpp"
#include <iostream>

int main()
{
	try 
	{
		std::srand(std::time(0));
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		Span sptest = Span(10000);
		std::vector<int> test;
		for (int i = 0; i < 10000; i++)
			test.push_back(std::rand());
		std::cout << test.size() << std::endl;
		sptest.addNumber(test);
		std::cout << "sptest.length=" << sptest.getLength() << std::endl;
		std::cout << "sptest.Fill=" << sptest.getFill() << std::endl;
		std::cout << sptest.shortestSpan() << std::endl;
		std::cout << sptest.longestSpan() << std::endl;

		Span sptest2 = Span(10000);
		sptest2.addNumber(test.begin(), test.end());
		std::cout << "sptest2.length=" << sptest2.getLength() << std::endl;
		std::cout << "sptest2.Fill=" << sptest2.getFill() << std::endl;
		std::cout << sptest2.shortestSpan() << std::endl;
		std::cout << sptest2.longestSpan() << std::endl;

		return 0;
	}
	catch  (std::exception& e)
	{
		std::cout <<"Error: " << e.what() << std::endl;
	}
	return (0);
	
}