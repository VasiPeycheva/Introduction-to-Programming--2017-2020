#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	if ((a > 0 && b > 0 && c > 0) &&
	   (a + b > c) && (b + c > a) && (a + c > b))
	{
		std::cout << "Exists\n";
	}
	else
	{
		std::cout << "Doesn't Exists\n";
	}

	return 0;
}