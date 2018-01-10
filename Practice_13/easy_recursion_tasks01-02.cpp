#include <iostream>
using namespace std;

/*************** Task 1 ***************/

int factorial(int number)
{
	if (number == 1) return 1;
	return number* factorial(number - 1);
}

/*************** Task 2 ***************/

//main logic
bool isPrimeRec(int number, int stop, int i)
{
	if (number == 1 || number == 2)
		return true;
	if (number % i == 0) 
		return false;
	if (i == stop) 
		return true;
	return isPrimeRec(number, stop, i + 1);
}

//wrapper function
bool isPrime(int number)
{
	return isPrimeRec(number, sqrt(number), 2);
}


int main()
{
	int number;

	// task 1
	cin >> number;
	cout << numberfactoriel(number) << endl;

	// task 2
	cin >> number;
	cout << isPrime(number) << endl;
	
}