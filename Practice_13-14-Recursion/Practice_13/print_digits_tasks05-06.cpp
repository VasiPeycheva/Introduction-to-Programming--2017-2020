#include <iostream>
using namespace std;

// PAY ATTENTION how swapping two code lines changes the whole program

/*************** Task 5 ***************/
void printForward(unsigned int number)
{
	if (number <= 0)
		return;
	printForward(number / 10);
	cout << (number % 10) << " ";
}

/*************** Task 6 ***************/
void printBackward(unsigned int number)
{
	if (number <= 0)
		return;
	cout << (number % 10) << " ";
	printBackward(number / 10);
}


int main()
{
	unsigned int number;
	cin >> number;
	
	// task 5
	cout << "Forward: "; 
	printForward(number);
	cout << endl;

	// task 6
	cout << "Backward: ";
	printBackward(number);
	cout << endl;
}