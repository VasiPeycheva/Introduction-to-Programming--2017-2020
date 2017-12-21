#include <iostream>

using namespace std;
int main()
{
	unsigned int n;
	cout << "Input a number: ";
	cin >> n;

	//Bad way
	/*unsigned short first = 0, sec = 0;
	first |= (n >> 16) ;
	sec |= n;
	unsigned int n2 = 0;
	n2 = ((n2 | first) | ~sec);*/

	//Good way
	unsigned short mask = 0xFFFF;
	cout << "Same number but with flipped first 16 bits: \n" << (n^mask) << endl;


	return 0;
}