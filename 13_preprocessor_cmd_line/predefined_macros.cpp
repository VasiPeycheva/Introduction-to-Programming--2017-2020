/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   predefined_macros.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  Some predefined macros.
 * @see    https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp_3.html#SEC20
 */

#include <iostream>

int main() {

	std::cout << "This is the line number " << __LINE__;
	std::cout << " of file " << __FILE__ << ".\n";
	std::cout << "It's compilation began on " << __DATE__;
	std::cout << " at " << __TIME__ << ".\n";
	std::cout << "C++ version: " << __cplusplus << std::endl;

	return 0;
}
