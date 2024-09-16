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

#include <iostream>


int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	if (a >= 100'000 || b >= 100'000 || c >= 100'000)
	{

		std::cout << "error\n";
		return 0;
	}
	if(a<0 || b<0 || c<0 )
	{

		std::cout << "error\n";
		return 0;
	}

	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";

	if (a >= b && b >= c)
	{
		std::cout << a - c << "\n";
		return 0;
	}
	if (b >= a && a >= c)
	{
		std::cout << b - c << "\n";
		return 0;
	}
	if (c >= b && b >= a)
	{
		std::cout << c - a << "\n";
		return 0;
	}
	if (c >= a && a >= b)
	{
		std::cout << c - b << "\n";
		return 0;
	}
	if (b >= c && c >= a)
	{
		std::cout << b - a << "\n";
		return 0;
	}
	if (a>=c && c>=b)
	{
		std::cout << a - b << "\n";
		return 0;
	}
	if (c>=a && a>=b)
	{
		std::cout << c - b << "\n";
		return 0;
	}


}
