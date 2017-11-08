#include<iostream>


int main() {

	unsigned int N;

	std::cin >> N;

	unsigned int currentNumber;
	unsigned long long sumDigits = 0;

	for (int i = 0; i < N; i++){

		std::cin >> currentNumber;

		//for each input number we are
		//adding its digits to the sum
		while (currentNumber) {

			sumDigits += (currentNumber % 10);
			currentNumber /= 10;

		}
	}

	std::cout << "sum of the digits is : " << sumDigits;


	return 0;
}