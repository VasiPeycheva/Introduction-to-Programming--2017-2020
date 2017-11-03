#include<iostream>

int main() {

	unsigned long long a,b;
	unsigned long long sum = 0;

	std::cin >> a >> b;

	//helpers
	unsigned long long sq;
	bool isPrimeCurrent = true;

	for (unsigned long long i = a; i < b; i++) {
		
		if (i <= 2) {
			break;
		}

		sq = sqrt(i);
		isPrimeCurrent = true;

		for (unsigned long long j = 2; j <= sq; j++) {

			if (i % j == 0) {

				isPrimeCurrent = false;
				break;
			}

		}

		if (isPrimeCurrent)
			sum += i;

	}

	std::cout << "the sum is : " << sum << '\n';

	return 0;
}