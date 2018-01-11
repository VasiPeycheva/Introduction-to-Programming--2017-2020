#include <iostream>
using namespace std;

const int MAX = 12;

/*************** Task 1 ***************/

unsigned int factorial(unsigned int number)
{
	//limit
	if (number > MAX)
		return 0;
	if (number == 0 || number == 1) 
		return 1;
	return number* factorial(number - 1);
}

/*************** Task 2 ***************/

//main logic
bool isPrimeRec(unsigned int number, unsigned int stop, unsigned int i)
{
	if (number == 1 || number == 2)
		return true;
	if (number % i == 0) 
		return false;
	if (i == stop) 
		return true;
	return isPrimeRec(number, stop, i + 1);
}

// "wrapper function" is a function which wraps another function (in our example the recursive one). 
// It's essentially another function which calls the actual function.
bool isPrime(unsigned int number)
{
	return isPrimeRec(number, sqrt(number), 2);
}


int main()
{
	unsigned int number;

	// task 1
	cin >> number;
	cout << factorial(number) << endl;

	// task 2
	cin >> number;
	if (isPrime(number))
		cout << "is prime \n";
	else
		cout << "not prime \n";

	return 0;
}

