/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_01.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 1 from practice 3.
  */

#include <iostream>

int main() {

	unsigned int a, b, c;
	// read the numbers
	std::cin >> a >> b >> c;


    // create a compare tree with all possible outcomes ->
    // there are 3! = 6 total different relations
	if (a > b) {
		if (a > c) { // a is the largest one
			if (b > c) {
				std::cout << a << " > " << b << " > " << c << std::endl;
			} else { // b <= c
				std::cout << a << " > " << c << " >= " << b << std::endl;
			}
		} else { // a > b && a <= c
			std::cout << c << " >= " << a << " > " << b << std::endl;
		}
	} else { // a <= b
		if (b > c) {
			if (a > c) {
				std::cout << b << " >= " << a << " > " << c << std::endl;
			} else {
				std::cout << b << " > " << c << " >= " << a << std::endl;
			}
		} else { // b <= c
			std::cout << c << " >= " << b << " >= " << a << std::endl;
		}
	}

	return 0;
}
