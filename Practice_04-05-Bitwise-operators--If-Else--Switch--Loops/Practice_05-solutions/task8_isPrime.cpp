#include<iostream>

int main() {

	unsigned long long N;

	std::cin >> N;

	std::cout << "N is ";

	//is 1 really  a prime ?
	if (N <= 2)
		std::cout << "prime!\n";

	unsigned long long sq = sqrt(N);

	//trying to find a number which can divide the given one
	//if there isn't such a number, the given is a prime
	for (unsigned long long i = 2; i <= sq; i++) {

		if (N % i == 0) {

			std::cout << "compose!\n";
			return 0; //ending the program

		}

	}

	std::cout << "prime!\n";

	return 0;
}
