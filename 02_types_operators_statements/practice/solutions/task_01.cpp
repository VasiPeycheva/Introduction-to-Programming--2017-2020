/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_01.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 1 from practice 2.
 */

#include <iostream>

int main() {

    short int num;

    // read input
	std::cout << "Enter a three-digit number: " << std::endl;
	std::cin >> num;

    // validate input
	if (num < 100 || num > 999) {
        std::cout << "Invalid input!" << std::endl;
        return 1; // exit the program
	}

    // output results
	std::cout << num % 10        // last digit
	          << (num / 10) % 10 // then the middle digit
	          << num / 100       // and the first digit
	          << std::endl;
	return 0;
}
