/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_11.cpp
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for task 11 from practice 3.
  */

#include <iostream>

int main() {

	unsigned int number;
	std::cin >> number;

	while (number) {
		// we print the last digit
		std::cout << number % 10 << ' ';
		// then we 'cut' it from the number
		number /= 10;
	}

	return 0;
}
