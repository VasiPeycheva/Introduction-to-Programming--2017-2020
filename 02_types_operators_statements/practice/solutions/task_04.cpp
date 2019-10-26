/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_04.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 4 from practice 2.
 */

#include <iostream>
#include <cmath> // std::sqrt - gives the square root of a number

int main() {

	// by given side and height
	unsigned short side, height;
	std::cout << "Input side: ";
	std::cin >> side;
	std::cout << "Input height: ";
	std::cin >> height;
	float area = (side * height) / 2.0f;
	std::cout << "Area: " << area << std::endl;

	// by given three valid sides
	unsigned short a, b, c;
	std::cout << "Input sides: ";
	std::cin >> a >> b >> c;
	float semi_per = (a + b + c) / 2.0f; // calculate the semi-parameter
	// calculate the area, using Heron's formula
    area = std::sqrt(semi_per * (semi_per - a) * (semi_per - b) * (semi_per - c));
	std::cout << "Area: " << area << std::endl;

	return 0;
}
