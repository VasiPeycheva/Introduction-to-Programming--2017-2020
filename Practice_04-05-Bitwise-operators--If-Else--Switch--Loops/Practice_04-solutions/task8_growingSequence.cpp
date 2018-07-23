#include <iostream>

using namespace std;

int main()
{
	int previous;
	int number;

	cin >> previous;

	while (true)
	{
		cin >> number;

		if(number < previous)
			break;

		previous = number;
	}

	return 0;
}