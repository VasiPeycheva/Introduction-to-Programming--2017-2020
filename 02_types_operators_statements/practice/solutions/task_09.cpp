/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_09.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 9 from practice 2.
 */

#include <iostream>
#include <cmath>

int main() {

	int x1, y1, x2, y2;

	std::cout << "Input x, y for point A: ";
	std::cin >> x1 >> y1;
	std::cout << "Input x, y for point B: ";
	std::cin >> x2 >> y2;

	std::cout << "Distance between A("
              << x1 << ", " << y1
              << ") and B("
              << x2 << ", " << y2
              << ") is "
              << std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
              << std::endl;

	return 0;
}
