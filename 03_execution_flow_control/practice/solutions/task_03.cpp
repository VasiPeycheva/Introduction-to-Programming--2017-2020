/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_03.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 3 from practice 3.
  */

#include <iostream>

int main() {

	unsigned int number;
	std::cin >> number;

	// sizeof(<type>) returns how many bytes is the passed type
	// we are traversing the bits from left to right
	for (short int i = (sizeof(unsigned int) * 8) - 1; i >= 0; i--) {
		// we create a "mask", which have only one "1" and many zeros,
		// the "1" is positioned on the i-th bit.
		std::cout << ((number & (1 << i)) ? '1' : '0');

		if (i % 8 == 0 && i) std::cout << '\''; // print quotes for better readability
	}

	std::cout << std::endl;

	return 0;
}
