#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

/******** From Class ********/
// sum all numbers in the range 1 ... n

// linear recursion
unsigned int sumLinear(unsigned int num,unsigned int result)
{
	if (num == 0)
		return result;
	return sumLinear(num - 1, result + num);
}

// tail recursion
unsigned int sumTail(unsigned int num)
{
	if (num == 0)
		return 0;
	return num + sumTail(num - 1);
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


int main()
{
	double num = 5;
	double resultLinear = divLinear(num, 1);
	cout << "DivLinear " << resultLinear << std::endl;
	cout << "DivTail " << divTail(num) << std::endl;

	return 0;
}














