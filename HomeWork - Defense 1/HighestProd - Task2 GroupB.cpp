#include <iostream>
/*
	Second Task :B
	Write a program which takes from input positive integer N. Then the program should take
	N integers. You should print the highest product of three consecutive elements smaller than 10^3.
	Examples:           Input:                      Output:
	                    5  2 5 4 3 5                  60
	                    7  5 6 0 10 1 15 -3           150
	                    5  1 2 8 4 5                  160
*/

int main()
{
	unsigned int number;
	short prePrev=1, prev=1, curr=1;
	int maxProd = -1000*1000*1000 - 10, curProd = -1000*1000*1000 - 10;

	std::cin >> number;

	if (number < 3)
	{
		switch (number)
		{
		case 2:std::cin >> prev;
		case 1:std::cin >> curr;
		}

		switch (number)
		{
		case 2:std::cout << prev*curr;
			break;
		case 1:std::cout<< curr;
			break;
		}

		std::cout << '\n';
		return 0;
	}
	else
	{
		std::cin >> prePrev >> prev;
		for (int i = 2; i < number; i++)
		{
			std::cin >> curr;
			curProd = curr*prev*prePrev;
			if (curProd>maxProd)
			{
				maxProd = curProd;
			}
			prePrev = prev;
			prev = curr;
		}
	}

	std::cout << maxProd<<'\n';
	
	return 0;
}