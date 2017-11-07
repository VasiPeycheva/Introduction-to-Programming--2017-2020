#include<iostream>
#include<math.h>


int main() {

	unsigned int number,numberCopy;
	unsigned int digitsCount = 0;


	std::cin >> number;

	//for task6
	numberCopy = number;

	//using some math
	std::cout << "math : " << (unsigned int)(1 + log10(number)) << '\n';



	while (number) { // same as number != 0

		digitsCount++;
		number /= 10;

	}


	std::cout <<"simple loop : " << digitsCount << '\n';

	/*
	std::cout << "task 6 result : \n";
	while (numberCopy) { 

		std::cout << numberCopy % 10 << ' ';
		numberCopy /= 10;

	}
	*/


	return 0;
}