#include <iostream>
/*
Task: Write program which prints to standart output all numbers
		divisible by three from 1 to n.
Examples:       Input:           Output:
				  3                3
				  10			   3 6 9
				  2                No divisible
*/
int main()
{
	unsigned int to;
	std::cout << "Enter end of the interval: ";
	std::cin >> to;
	if (to<3)
	{
		std::cout << "No divisible\n";
		return 0;
	}

	for (int i = 3; i <= to; i+=3)
	{
		std::cout << i << ' ';
	}

	std::cout	<< '\n'
				<< "These are all divisibles by three from 1 to " << to
				<<'\n';
	return 0;
}