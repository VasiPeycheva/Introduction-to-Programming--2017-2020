#include <iostream>

using namespace std;

int main()
{
	short number;

	do
	{
		cin >> number;
	} while (number < 0 || number > 100);

	return 0;
}