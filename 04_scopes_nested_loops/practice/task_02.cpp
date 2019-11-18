/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_02.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for task 2 from practice 4.
  */

#include <iostream>

int main() {

	unsigned int N;

	std::cin >> N;

	unsigned int current_number;
	unsigned long long sum_digits = 0;

	for (int i = 0; i < N; i++){
		std::cin >> current_number;

		// for each input number we are
		// adding its digits to the sum
		while (current_number) {
			sum_digits += (current_number % 10);
			current_number /= 10;
		}
	}

	std::cout << "sum of the digits is : "
	          << sum_digits << std::endl;
	return 0;
}
