/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_10.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 9 from practice 2.
 */

#include <iostream>
#include <cmath>

int main() {

	int x, y;

	std::cout << "Input x, y for the point : ";
	std::cin >> x >> y;
	bool is_inside = false; // assume, that the point is outside

	if (y > 0) {
        // we should check if we are in the semi-circle
        int r = 2 * 2; // circle's radius (powered by 2, to avoid floating point calculations)
        // the distance from the point to (0, 0) [where the center of the circle is]
        int dist_squared = (x * x) + (y * y);
        if (dist_squared <= r) {
            is_inside = true;
        }

	} else {
        // we should check if we are in the rectangle
        if ((std::abs(x) <=  1) &&
            (std::abs(y) <=  4)) {
            is_inside = true;
        }
	}

    std::cout << "The point is ";
    if (is_inside) {
        std::cout << "inside!" << std::endl;
    } else {
        std::cout << "outside!" << std::endl;
    }

	return 0;
}
