#include <iostream>


int main()
{
	int a = 0;
	std::cin >> a;

	if (a > 0 && a < 3)
	{
		std::cout << "winter\n";
	}
	if (a > 2 && a < 6)
	{
		std::cout << "spring\n";
	}
	if (a > 5 && a < 9)
	{
		std::cout << "summer\n";
	}
	if (a > 8 && a < 12)
	{
		std::cout << "autumn\n";
	}
	if (a > 11 && a < 13)
	{
		std::cout << "winter\n";
	}

}

