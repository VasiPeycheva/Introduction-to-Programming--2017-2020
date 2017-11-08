#include<iostream>

int main() {

	unsigned int N;

	std::cin >> N;

	std::cout << "N = ";

	for (int i = 2; i <= N; i++) {

		//dividing the numbers as many times as it can
		while (N % i == 0) {

			std::cout << i;
			N /= i;

			if (N != 1) //still have divisors 
				std::cout << " * ";
			

		}

	}

	std::cout << '\n';


	return 0;
}