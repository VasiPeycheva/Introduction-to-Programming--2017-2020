/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_02.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 2 from practice 2.
 */

#include <iostream>

int main() {

	bool a, b;

    // read input
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;

    // output results
	std::cout << "a & b = " << (a & b) << std::endl;
	std::cout << "a | b = " << (a | b) << std::endl;
	std::cout << "a ^ b = " << (a ^ b) << std::endl;

	return 0;
}
