/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_12.cpp
  * @author Ivan Filipov
  * @date   11.2019
  * @brief  Solution for task 12 from practice 3.
  */

#include <iostream>

// calculated by just making tests
const unsigned short N_LIMIT = 23;

int main() {

	unsigned short n;
	unsigned long long fact = 1;

	std::cin >> n;

	if (n > N_LIMIT) {
		std::cout << "Can calculate only to " << N_LIMIT << "! which equals to ";
		n = N_LIMIT;
	}

	for (short i = 2; i <= n; i++)
		fact *= i;

	std::cout << fact << std::endl;

	return 0;
}
