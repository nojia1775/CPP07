#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _arr(NULL)
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
	for (unsigned int i = 0 ; i < n ; i++)
		_arr[i] = T();
	std::cout << "Array constructor called\n";
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
	_arr = new T[other._size];
	for (size_t i = 0 ; i < other._size ; i++)
		_arr[i] = other._arr[i];
	std::cout << "Array copy constructor called\n";
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr = new T[other._size];
		for (int i = 0 ; i < other._size ; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (_arr == NULL || index > _size - 1)
		throw OutOfRange();
	else
		return _arr[index];
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template <typename T>
const char	*Array<T>::OutOfRange::what(void) const throw()
{
	return "Index is out of range";
}