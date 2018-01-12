#include <iostream>
using namespace std;

/******** From Class ********/
// sum all numbers in the range 1 ... n

// linear recursion
unsigned int sumLinear(unsigned int num,unsigned int result)
{
	if (num == 0)
		return result;
	return sum(num - 1, result + num);
}

// tail recursion
unsigned int sumTail(unsigned int num)
{
	if (num == 0)
		return 0;
	return num + sum1(num - 1);
}

/******** Bonus ********/
// What return each function? Why? 

// linear recursion
double divLinear(double num, double result)
{
	if (num == 1)
		return result;
	return divLinear(num - 1, result / num);
}

// tail recursion
double divTail(double num)
{
	if (num == 0)
		return 1;
	return num / divTail(num - 1);
}
