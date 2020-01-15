/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_05-06.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for recursion tasks from practice 11.
  */

#include <iostream>

// PAY ATTENTION how swapping two code lines changes the whole program
/*************** Task 5 ***************/
void print_forward(unsigned int number) {
	if (number <= 0)
		return;
	print_forward(number / 10);
	std::cout << (number % 10) << " ";
}

/*************** Task 6 ***************/
void print_backward(unsigned int number) {
	
	if (number <= 0)
		return;

	std::cout << (number % 10) << " ";
	print_backward(number / 10);
}

int main() {
	
	unsigned int number;
	std::cin >> number;
	
	// task_05
	std::cout << "Forward: "; 
	print_forward(number);
	std::cout << std::endl;

	// task_06
	std::cout << "Backward: ";
	print_backward(number);
	std::cout << std::endl;

	return 0;
}