#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
private:
	std::vector<int>		_vec;
	unsigned int		_length;
	unsigned int		_fill;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &copy);

	Span &operator=(Span const &copy);

	void	addNumber(int n);
	void	addNumber(std::vector<int> range);
	void	addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	unsigned int	getLength();
	unsigned int	getFill();



	~Span();

	class NotEnoughSpace : public std::exception
	{
		public :
			virtual const char *what() const throw()
			{
				return ("No more space");
			}
	};

	class NotEnoughMember : public std::exception
	{
		public :
			virtual const char *what() const throw()
			{
				return ("Not enough member");
			}
	};
};

#endif