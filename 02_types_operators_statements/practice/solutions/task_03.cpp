/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_03.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 3 from practice 2.
 */

#include <iostream>

int main() {

    int a, b, c;
	std::cin >> a >> b >> c;
    std::cout << "Triangle with sides (" << a << ", " << b << ", " << c << ") - ";

	if ((a > 0 && b > 0 && c > 0) &&                 // check all positive
	    (a + b > c) && (b + c > a) && (a + c > b)) { // and the triangle inequality rule
		std::cout << "exists!" << std::endl;
	} else {
		std::cout << "doesn't exist!" << std::endl;
	}

	return 0;
}
