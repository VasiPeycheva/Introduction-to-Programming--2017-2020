/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_06.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for task 6 from practice 4.
  */

#include <iostream>

int main() {

	unsigned int x, y;
	std::cin >> x >> y;

	if (x <= 1 || y <= 1) {
		std::cout << "can't draw! \n";
		return 0;
	}

	// top line
	for (unsigned int i = 0; i < x; i++) {
		std::cout << "* ";
	}
	std::cout << std::endl;

	// the side lines
	for (unsigned int i = 0; i < y - 2; i++) {
		std::cout << "* ";
		for (unsigned int j = 0; j < x - 2; j++) {
			std::cout << "  ";
		}
		std::cout << '*' << std::endl;
	}

	// the bottom line
	for (unsigned int i = 0; i < x; i++) {
		std::cout << "* ";
	}

	std::cout << std::endl;
	return 0;
}
