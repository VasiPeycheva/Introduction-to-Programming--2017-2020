/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_04.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 4 from practice 3.
  */

#include <iostream>

int main() {

	unsigned int A, a1, a2, a3;

	std::cout << "Input a number: ";
	std::cin >> A;
	std::cout << "Input 3 bit positions [0-31] (divided with spaces): ";
	std::cin >> a1 >> a2 >> a3;
	// we lift the bits by using | bitwise operator
	unsigned int A_prim = ((A | (1 << a1)) | (1 << a2)) | (1 << a3);
	std::cout << "The new integer is: " << A_prim << std::endl;
	std::cout << "A' - A = " << A_prim - A << std::endl;

	return 0;
}
