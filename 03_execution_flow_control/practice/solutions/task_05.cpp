/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_05.cpp
  * @author Vasilena Peycheva
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 5 from practice 3.
  */

#include <iostream>

int main() {

	unsigned int n;
	std::cout << "Input a number: ";
	std::cin >> n;

	// hard way
	/*unsigned short first = 0, sec = 0;
	first |= (n >> 16) ;
	sec |= n;
	unsigned int n2 = 0;
	n2 = ((n2 | first) | ~sec);*/

	// much easier approach
	unsigned short mask = 0xFFFF;
	std::cout << "Same number but with flipped first 16 bits: " << (n ^ mask) << std::endl;

	return 0;
}
