/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_05.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 5 from practice 4.
  */

#include <iostream>

int main() {

	unsigned int n;
	unsigned int sum = 0;
	int number_to_add; // helper number
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		number_to_add = i;

		for (int j = 1; j < i; j++) { // multiply our number (i - 1) times
			number_to_add *= i;
		}

		sum += number_to_add;
	}

	std::cout << "Sum: " << sum << std::endl;
	return 0;
}
