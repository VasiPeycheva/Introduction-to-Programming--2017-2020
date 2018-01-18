#include<iostream>

const unsigned int DIGITS_COUNT = 10;
//false there is not such digit
//true there is
bool digitSeen[DIGITS_COUNT];

bool hasSameDigits_rec(unsigned int num) {

	//only one digit left
	if (num < 10)
		return digitSeen[num];
	

	//more than one digit in the number
	//check the last one
	if (digitSeen[num % 10]) //if seen
		return true;

	//if not seen
	digitSeen[num % 10] = true;

	return hasSameDigits_rec(num / 10);

}


bool hasSameDigits(unsigned int num) {

	//ensure that all cell are marked as no such digit
	memset(digitSeen, false, DIGITS_COUNT * sizeof(bool));


	if (num < 10)
		return false;

	//last digit is seen
	digitSeen[num % 10] = true;

	return hasSameDigits_rec(num / 10);

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