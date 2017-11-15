#include <iostream>
//MSB --> Most Significant Bit
//LSB --> Least Significant Bit
int main()
{
	unsigned int number;
	std::cin >> number;		//Example 11101...101  

							//Number of shifted bits:    30 ... Full it with zeros
	unsigned int mask = number << 30;			//    111...1|01 0...00
							//mask = 01...00;

							//Shift number and drop the two MSB bits: 
	unsigned int newNumber = number<<2;				// 11|101...10100
							//newNumber = 101...10100;

							//Shift newNumber and full it with two zeros
	newNumber = newNumber >> 2;	                 // 00101...101|00
							//newNumber = 00101...101;
	newNumber = newNumber | mask;
							//newNumber = 01101...101;
	std::cout << "The new number with two MSBs same as two LSBs is " << newNumber<<'\n';
	return 0;
}