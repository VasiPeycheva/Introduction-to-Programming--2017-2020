#include <iostream>

using namespace std;

int main()
{
	unsigned int N, b1, b2, b3;

	cout << "Input a number: ";
	cin >> N;
	cout << "Input 3 bit positions [0-31] (divided with space): ";
	cin >> b1 >> b2 >> b3;
	unsigned int newNum = ((N | 1 << b1) | 1 << b2) | 1 << b3;
	cout << "The new integer is: " << newNum << '\n';

	return 0;
}