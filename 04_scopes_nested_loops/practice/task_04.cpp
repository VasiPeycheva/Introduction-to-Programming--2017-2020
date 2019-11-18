/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_04.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 4 from practice 4.
  */

#include <iostream>

int main() {

	int number;

	for (int f_digit = 1; f_digit <= 9; f_digit++) {
		for (int s_digit = 0; s_digit <= 9; s_digit++) {
			for (int t_digit = 0; t_digit <= 9; t_digit++) {
				if (f_digit != s_digit &&
				    f_digit != t_digit &&
					s_digit != t_digit) {
					number = 100 * f_digit + 10 * s_digit + t_digit;
					std::cout << number << std::endl;
				}
			}
		}
	}

	return 0;
}
