#include<iostream>

const unsigned short LIMIT = 23;

int main() {

	unsigned short N;
	unsigned long long fact = 1;

	std::cin >> N;

	if (N > LIMIT)
	{
		std::cout << "can calculate only to " << LIMIT << "which is ";
		N = LIMIT;
	}

	for (short i = 2; i < N; i++)
		fact *= i;

	std::cout << fact << '\n';

	return 0;
}