#include<iostream>

int main() {

	unsigned int N;
	int currentNum, sum = 0;

	std::cin >> N;


	for (int i = 0; i < N; i++) {

		std::cin >> currentNum; //reading the new num 
		sum += currentNum; 		//adding it to the sum

	}

	//we should 'cast' our variables to double in oreder to calculate the exact result
	std::cout << "the average is " << (double)sum / (double)N << '\n';

	return 0;
}