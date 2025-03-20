#ifndef ITER_HPP

# define ITER_HPP

# include <iostream>
# include <cctype>

template <typename T, typename F>
void	iter(T *tab, size_t size, F f)
{
	for (size_t i = 0 ; i < size ; i++)
		f(tab[i]);
}

#endif