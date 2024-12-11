#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _arr(nullptr)
{
	std::cout << "Array default constructor called\n";
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array destructor called\n";
	delete[] _arr;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n];
	std::cout << "Array constructor called\n";
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
	_arr = new other._arr;
	std::cout << "Array copy constructor called\n";
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr = new other._arr;
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index > _size)
		throw OutOfRange();
	else
		return _arr[index];
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return _size;
}

template <typename T>
const char	*Array<T>::OutOfRange::what(void) const throw()
{
	return "Index is out of range";
}