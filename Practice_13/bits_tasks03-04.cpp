#include <iostream>
using namespace std;

/*************** Task 3 ***************/
//print the binary representation of a number

// "actual function"
void printBitsRec(unsigned int number, unsigned int position)
{
	unsigned int mask = 1 << (position - 1);
	cout << ((number&mask) ? "1" : "0");
	if (position == 1)
		return;
	else
		return printBitsRec(number, position - 1);
}

// example of a "wrapper function"
void printBits(unsigned int number)
{
	unsigned int position = sizeof(unsigned int) * 8; 
	return printBitsRec(number, position);
}

/*************** Task 4 ***************/
//print the number of zeros and ones in the binary representation of a number

// main logic
void countBitsRec(unsigned int number, unsigned int position, int &zeroes, int &ones)
{
	unsigned int mask = 1 << (position - 1);
	((number&mask) ? ones++ : zeroes++);
	if (position == 1)
		return;
	else
		return countBitsRec(number, position - 1, zeroes, ones);
}

void countBits(unsigned int number)
{
	int zeroes = 0;
	int ones = 0;
	unsigned int position = sizeof(unsigned int) * 8;
	countBitsRec(number, position,zeroes,ones);
	cout << "In number: " << number << " we have " << zeroes << " zeroes and " << ones << " ones! \n";
 }

int main()
{
	unsigned int number;
	cin >> number;
	printBits(number);
	cout << endl;
	countBits(number);
	cout << endl;
}
