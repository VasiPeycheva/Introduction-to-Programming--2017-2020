//Devide two integers and prints
//the quotient and the remainder

#include <iostream>

using namespace std;

int main()
{
	int p, q;
	cout << "p= ";
	cin >> p;
	cout << "(cannot be 0!) q= ";
	cin >> q;

	cout << "quotient: " << p / q << '\n';
	cout << "remainder: " << p % q << '\n';

	return 0;
}