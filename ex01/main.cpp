#include "iter.hpp"

template <typename T>
void	print(const T& c) { std::cout << c; }

int	main(void)
{
	int tab1[] = {1, 2, 3, 4};
	iter(tab1, 4, print<int>);
	std::cout << "\n";
	char tab2[] = "test\n";
	iter(tab2, 5, print<char>);
	std::string tab3[] = {
		"hello",
		" this is ",
		"a test\n"
	};
	iter(tab3, 3, print<std::string>);
	return 0;
}