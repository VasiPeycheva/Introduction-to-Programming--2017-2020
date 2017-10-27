#include <iostream>

using namespace std;

int main()
{
	unsigned int number;
	unsigned int mask;

	cin >> number;

	for (unsigned int i = sizeof(unsigned int) * 8; i > 0 ; i--)
	{
		mask = 1;
		mask = mask << (i-1);
		cout << ((number&mask) ? "1" : "0");
	}

	return 0;
}