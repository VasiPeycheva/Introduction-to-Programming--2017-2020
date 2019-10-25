/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_06.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 6 from practice 2.
 */

#include <iostream>

int main() {

	int p, q;
	std::cout << "p = ";
	std::cin >> p;
	std::cout << "q cannot be 0! But try if you dare..." << std::endl;
	std::cout << "q = ";
	std::cin >> q;

	std::cout << "quotient: "  << p / q << std::endl;
	std::cout << "remainder: " << p % q << std::endl;

	return 0;
}
