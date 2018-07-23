#include<iostream>

bool hasSameDigits_rec(unsigned int num, short curDigit) {

	if (num < 10) // only one digit
		return num == curDigit;

	if (num % 10 == curDigit) // check the last one
		return true;

	if (hasSameDigits_rec(num / 10, curDigit)) //same digit in the rest of the number
		return true;
	else
		return hasSameDigits_rec(num / 10, num % 10); // try with the next digit
}

bool hasSameDigits(unsigned int num) {

	if (num < 10)
		return false;

	return hasSameDigits_rec(num / 10, num % 10);

}



int main() {

	unsigned int num = 125453;

	std::cout << "has same digits " << num << " ?\n";

	if (hasSameDigits(num))
		std::cout << "yes\n";
	else
		std::cout << "no\n";


	return 0;
}