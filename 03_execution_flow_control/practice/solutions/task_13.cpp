/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_13.cpp
  * @author Ivan Filipov
  * @date   11.2019
  * @brief  Solution for task 13 from practice 3.
  */

#include <iostream>
#include <cmath>

int main() {

	unsigned long long N;
	std::cin >> N;
	std::cout << "N is ";

	//is 1 really  a prime ?
	if (N <= 2)
		std::cout << "prime!" << std::endl;

	unsigned long long sq = std::sqrt(N);

	// trying to find a number which can divide the given one
	// if there isn't such a number, than the given is prime
	for (unsigned long long i = 2; i <= sq; i++) {
		if (N % i == 0) {
			std::cout << "compose!" << std::endl;
			return 0; // exit the program
		}
	}

	std::cout << "prime!" << std::endl;

	return 0;
}
