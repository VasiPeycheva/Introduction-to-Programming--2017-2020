/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_08.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 8 from practice 2.
 */

#include <iostream>

int main() {

	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
    std::cout << "abs(" << number << ") = ";

	if (number < 0) {
		std::cout << -number << std::endl;
	} else {
		std::cout << number  << std::endl;
	}

	return 0;
}
