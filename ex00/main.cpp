#include "whatever.hpp"

int	main(void)
{
	int a = 10;
	int b = 42;
	::swap(a, b);
	std::cout << a << " " << b << "\n";
	double c = 10.1;
	double d = 42.09;
	::swap(c, d);
	std::cout << c << " " << d << "\n";
	char e = 'a';
	char f = 'z';
	::swap(e, f);
	std::cout << e << " " << f << "\n";
	std::string g = "chaine1";
	std::string h = "chaine2";
	::swap(g, h);
	std::cout << g << " " << h << "\n\n";
	std::cout << ::max(1, 2) << "\n";
	std::cout << ::max(1.9, -2.7) << "\n";
	std::cout << ::max('a', 'z') << "\n";
	std::cout << ::max(g, h) << "\n\n";
	std::cout << ::min(1, 2) << "\n";
	std::cout << ::min(1.9, -2.7) << "\n";
	std::cout << ::min('a', 'z') << "\n";
	std::cout << ::min(g, h) << "\n\n";
	return 0;
}