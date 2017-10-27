#include <iostream>

using namespace std;

int main()
{
	unsigned int n;
	unsigned int result = 0;
	cin >> n;

	for (unsigned int i = 1; i <= n; i++)
	{
		result += i; // result = result + i;
	}

	cout << result;

	return 0;
}