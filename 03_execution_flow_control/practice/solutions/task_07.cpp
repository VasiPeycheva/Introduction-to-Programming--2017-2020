/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /*
  * @file   task_07.cpp
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 7 from practice 3.
  */

#include <iostream>

int main() {

    int number;
	int previous;

	// we read the first number
	std::cin >> previous;
	int counter = 1;

	while (true) {
		std::cin >> number;

		// on every step we check if the next number is less that the previous one
		if (number < previous)
			break;

		// so that the next time we enter a new number, we got
		// access to the last one entered
		previous = number;
		counter++;
	}

	std::cout << std::endl << counter << std::endl;
	return 0;
}
