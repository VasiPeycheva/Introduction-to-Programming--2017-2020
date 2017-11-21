#include <iostream>
/*
	First Task :B
	Write a program which takes from input positive integer N and checks if the given number
	can be represented only by even powers of 2. You should print "yes" if it is true and
	"no" if it isn't.
	Example:			Input:				Output:
							1  (1=2^0)			"yes"				
							12 (12=2^3+2^2)		"no"
							20 (20=2^4+2^2)		"yes"
*/
int main()
{
	unsigned int number,mask=1;
	unsigned int currBit, bitCnt = 0;
	bool onlyEven = true;
	std::cin >> number;
	while (number)
	{
		if (bitCnt%2==1)
		{
			currBit = number&mask;
			if (currBit>0)
			{
				onlyEven = false;
				break;
			}
		}
		bitCnt++;
		number >>= 1;
	}

	if (onlyEven)
	{
		std::cout << "yes\n";
	}
	else
	{
		std::cout << "no\n";
	}

	return 0;

}