#include <iostream>
/*
	First Task :A
	Write a program which calculates the sum of the length of all sequences with 
	at least 2 equal bits in binary representation.
		Examples:		Input:					Output:
						 8 (0b1000)					3
						 60(ob111100)				6
						 11159(ob10101110010111)	8

*/
int main()
{
	unsigned int number,mask=1,
				previousBit=2,currBit,cntSeq=1,sum=0;
	std::cin >> number;

	while (number)
	{
		currBit = number&mask;
		if (currBit==previousBit)
		{
			cntSeq++;
		}
		else
		{
			if (cntSeq>1)
			{
				sum += cntSeq;
			}
			cntSeq = 1;
		}
		previousBit = currBit;
		number >>= 1;
	}
	sum += cntSeq > 1 ? cntSeq : 0;
	std::cout << sum << '\n';
	return 0;
}