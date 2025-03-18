#ifndef ARRAY_HPP

# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{
	private:
		unsigned int	_size;
		T		*_arr;

	public:
				Array(void);
				~Array(void);

				Array(unsigned int n);
				Array(const Array& other);
		Array&		operator=(const Array& other);

		T&		operator[](unsigned int index);
		unsigned int	size(void) const;

		class		OutOfRange : public std::exception
		{
			const char	*what(void) const throw();
		};
};

# include "Array.tpp"

#endif