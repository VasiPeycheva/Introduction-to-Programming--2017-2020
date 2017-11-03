#include<iostream>

int main() {

	unsigned int N;
	int currentNum, sum = 0;

	std::cin >> N;

	for (int i = 0; i < N; i++) {

		std::cin >> currentNum;
		sum += currentNum;

	}

	std::cout << "the average is " << (double)sum / (double)N << '\n';

	return 0;
}