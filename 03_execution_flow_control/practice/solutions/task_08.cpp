/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_08.cpp
  * @author Vasilena Peycheva
  * @author Ivan Filipov
  * @date   11.2019
  * @brief  Solution for task 8 from practice 2.
  */

#include <iostream>

int main() {

	unsigned int n;
	unsigned int sum = 0;
	std::cin >> n;

	for (unsigned int i = 1; i <= n; i++) {
		sum += i;
	}

	// using Gauss's formula; be careful, an overflow may occur
	unsigned int gauss_sum = ((n + 1) * n) / 2;

	std::cout << "Sum = " << sum << std::endl
              << "With maths: " << gauss_sum << std::endl;

	return 0;
}
