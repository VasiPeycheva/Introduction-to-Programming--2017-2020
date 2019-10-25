/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   task_05.cpp
 * @author Vasilena Peycheva
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Solution for task 5 from practice 2.
 */

#include <iostream>

int main() {

	int a, b, temp;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;

	// swap with temporary variable
	temp = a;
	a = b;
	b = temp;

	/* swap without help variable,
       using a simple arithmetic trick
	a += b;
	b = a - b;
	a = a - b;
	*/
    std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	return 0;
}
