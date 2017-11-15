#include <iostream>
/*
	Task: Write program which calculates sum of even numbers in given interval.
	Examples:       Input:           Output:
					2 6               12
					3 6               10
					1 1               0
*/
int main()
{
	unsigned int from, to;
	std::cout << "Enter the beginning of interval:\n";
	std::cin >> from;
	std::cout << "Enter the end of interval:\n";
	std::cin >> to;
	from = (from % 2 == 0) ? from : from + 1;
	unsigned long sum = 0;

	for (int i = from; i <= to; i+=2)
	{
		sum += i;
	}

	std::cout << "Sum is: " << sum<<'\n';
	return 0;
}