#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	
	if(num < 0)
	{
		std::cout << -number;
	}
	else
	{
		std::cout << number;
	}
	
	// trinary operator
	std::cout << (number < 0) ? -number : number << '\n';

	return 0;
}