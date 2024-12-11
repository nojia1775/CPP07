#include "Array.hpp"

int	main(void)
{
	Array<int> arr(2);
	Array<int> other = arr;
	try
	{
		other[1] = 10;
		std::cout << other[1] << "\n";
		std::cout << arr[1] << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}