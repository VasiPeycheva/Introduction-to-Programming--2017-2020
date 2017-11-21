#include <iostream>
/*
	Second Task:A
	Write a program which takes from input positive integer N. Then the program should take
	N integers. You should output the length of the longest non strictly decreasing sequence
	of these N integers.
	Example:			Input:				Output:
						4  5 3 4 5				2
						6  11 7 7 5 12 13		4
						5  1 2 3 4 5			1
*/

int main()
{
	unsigned int number; 
	int currNum, prevNum = INT32_MIN;
	unsigned int maxLength=1,currLength=1;
	std::cin >> number;

	for (int i = 0; i < number; i++)
	{
		std::cin >> currNum;
		if (currNum<=prevNum)
		{
			currLength++;
		}
		else
		{
			if (currLength>maxLength)
			{
				maxLength = currLength;
			}
			currLength = 1;
		}

		prevNum = currNum;
	}
	maxLength = currLength > maxLength ? currLength : maxLength;

	std::cout << maxLength << '\n';

	return 0;
}