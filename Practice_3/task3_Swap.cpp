/*Swap two variables*/
#include <iostream>

using namespace std;

int main()
{
	int a, b, temp;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;

	//swap with temporary variable
	temp = a;
	a = b;
	b = temp;

	/*swap without help variable
	a += b;
	b = a - b;
	a = a - b;
	*/

	cout << "a= " << a << '\n';
	cout << "b= " << b << '\n';

	return 0;
}