#include<iostream>

int main() {

	unsigned long long N;

	std::cin >> N;

	std::cout << "N is ";

	if (N <= 2) {

		std::cout << "prime!\n";

	}

	unsigned long long sq = sqrt(N);
	for (unsigned long long i = 2; i <= sq; i++) {

		if (N % i == 0) {

			std::cout << "compose!\n";
			return 0;

		}

	}

	std::cout << "prime!\n";

	return 0;
}