#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	class iterator
	{
	private:
		T *_ptr;

	public:
		iterator(void) : _ptr(0) {}
		iterator(T *ptr) : _ptr(ptr) {}
		iterator(const iterator &copy) : _ptr(copy._ptr) {}
		~iterator(void) {}
		
		iterator &operator++(void)
		{
			_ptr++;
			return (*this);
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			_ptr++;
			return (temp);
		}

		iterator &operator--(void)
		{
			_ptr--;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator temp = *this;
			_ptr--;
			return (temp);
		}

		T &operator*(void) const
		{
			return (*_ptr);
		}

		bool operator==(const iterator &ite)
		{
			return (this->_ptr == ite._ptr);
		}

		bool operator!=(const iterator &ite)
		{
			return (this-> _ptr != ite._ptr);
		}

		iterator	&operator+(int n)
		{
			while (n--)
				_ptr++;
			return (*this);	
		}

		iterator &operator-(int n)
		{
			while(n--)
				_ptr--;
			return (*this);
		}
	};

	MutantStack(void) {}
	MutantStack(const MutantStack &copy)
	{
		*this = copy;
	}

	~MutantStack(void) {}

	MutantStack &operator=(const MutantStack &copy)
	{
		MutantStack<T>	tempStack;
		MutantStack<T>	copyofcopy = copy;

		while (!this->empty())
			this->pop();
		
		while (!copyofcopy.empty())
		{
			tempStack.push(copyofcopy.top());
			copyofcopy.pop();
		}

		while (!tempStack.empty())
		{
			this->push(tempStack.top());
			tempStack.pop();
		}

		return (*this);
	}

	iterator begin()
	{
		return iterator(&this->top() - this->size() + 1);
	}

	iterator end()
	{
		return iterator(&this->top() + 1);
	}
};

#endif