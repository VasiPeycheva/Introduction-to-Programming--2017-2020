/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_10.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 10 from practice 3.
  */

#include <iostream>
#include <cmath> // std::log10()


int main() {

	unsigned int number;
	unsigned int digitsCount = 0;

	std::cin >> number;

	// using some math
	std::cout << "With math: " << (unsigned int)(1 + std::log10(number)) << std::endl;

	while (number) { // same as number != 0
		digitsCount++;
		number /= 10;
	}

	std::cout << "With simple loop: " << digitsCount << std::endl;

	return 0;
}
