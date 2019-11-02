/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_06.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 6 from practice 3.
  */

#include <iostream>
#include <iomanip>

const short int TIMES_TO_SHIFT = 8;

int main() {

	short int number;
	std::cin >> number;

	short int first_byte  = (number & 0xFF); // get the first byte only with mask
	short int second_byte = (number >> TIMES_TO_SHIFT); // shift the number, so the first 8bits will be dropped

	short int res = ((first_byte << TIMES_TO_SHIFT) | second_byte); // combine the bytes with swapped positions
	std::cout << "Number with switched bytes: " << res;

	return 0;
}


