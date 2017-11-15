#include <iostream>

int main()
{
	unsigned short from, to;
	unsigned int number,mask=1;
	std::cout << "Enter a number: \n";
	std::cin >> number;
	do
	{
		std::cout << "Enter a position to take bit from [0-31]: \n";
		std::cin >> from;
	} while (from>31);
	do
	{
		std::cout << "Enter a position to set bit to [0-31]: \n";
		std::cin >> to;
	} while (to>31);

	mask = number & mask << from;
	if (mask)
	{ 
		//if mask is true(>0) we have to set 1 
		number = number | (1 << to);  //110...11
								   // | 010...00	
	}
	else
	{
		//if mask is false(=0) we have to set 0
		number = number & ~(1 << to); //110..11
	}								//& 101..11

	std::cout << number;
}