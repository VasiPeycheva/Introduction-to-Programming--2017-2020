#include <iostream>

using namespace std;

int main()
{
	bool a;
	bool b;

	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	
	cout << "a & b = " << (a & b) << '\n';
	cout << "a | b = " << (a | b) << '\n';
	cout << "a ^ b = " << (a ^ b) << '\n';

	return 0;
}