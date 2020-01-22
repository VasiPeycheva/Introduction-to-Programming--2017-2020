/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   basic_example.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  The most basic example about function pointers in C/C++.
 */

#include <iostream>

// a simple function
int sum(int x, int y) {

	return x + y;
}

int main() {
    // the most basic example
    // foo is a pointer to function,
    // which takes 0 arguments and returns nothing (void)
    void(*foo)();

	// sum_fptr is a pointer to function which takes two integers
	// and returns an integer
	int(*sum_fptr)(int, int);

	// sum_fptr now points to the function "sum"
	sum_fptr = sum; // we can skip the '&' from [sum_fptr = &sum;]

	// now we can invoke the function through the pointer
	std::cout << sum_fptr(1, 2); // same as (*sum_fptr)(1, 2)

	return 0;
}
