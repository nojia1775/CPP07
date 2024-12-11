#include "iter.hpp"

int	main(void)
{
	int tab1[] = {1, 2, 3, 4};
	::iter(tab1, 4, aff);
	std::cout << "\n";
	char tab2[] = "test\n";
	::iter(tab2, 5, aff);
	std::string tab3[] = {
		"hello",
		" this is ",
		"a test\n"
	};
	::iter(tab3, 3, aff);
	return 0;
}