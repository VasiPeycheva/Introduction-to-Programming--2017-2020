/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_03.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for task 3 from practice 4.
  */

#include <iostream>

int main() {

	unsigned int N;
	std::cin >> N;
	std::cout << "N = ";

	for (int i = 2; i <= N; i++) {
		// dividing the numbers as many times as we can
		while (N % i == 0) {
			std::cout << i;
			N /= i;

			if (N != 1) //still have divisors
				std::cout << " * ";
		}
	}

	std::cout << std::endl;
	return 0;
}
