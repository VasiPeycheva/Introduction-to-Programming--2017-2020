/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_09.cpp
  * @author Vasilena Peycheva
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 9 from practice 3.
  */

#include<iostream>

int main() {

	unsigned int n;
    int current_num, sum = 0;

	std::cin >> n;

	for (unsigned int i = 0; i < n; i++) {
		std::cin >> current_num; // reading the new num
		sum += current_num; 		// adding it to the sum
	}

	// we should 'cast' our variables to double in oreder to calculate the exact result
	std::cout << "The average is: " << (double)sum / n << std::endl;

	return 0;
}
