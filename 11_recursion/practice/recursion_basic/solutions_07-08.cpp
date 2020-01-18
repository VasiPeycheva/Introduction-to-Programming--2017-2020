/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions_07-08.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for recursion tasks from practice 12.
  */

#include<iostream>

/*************** Task 7 ***************/
// the actual recursive function
void print_line_rec(unsigned int k, unsigned int it, unsigned long long result) {

	std::cout << result << ' ';

	if (it < k)
		print_line_rec(k, it + 1, result * 10);

	std::cout << result << ' ';
}

// the wrapper
void print_line(unsigned int k) {

	print_line_rec(k, 1, 10);
}


/*************** Task 8 ***************/
// just by following the recursive definition of the algorithm
int gcd(int a, int b) {

	return (b == 0) ? a : gcd(b, a % b);
}


int main() {

	// task_07 output
	std::cout << "Enter a positive number k >= 1, k = ";
	unsigned int k;
	std::cin >> k;

	if (k < 1)
		std::cout << "cheater!" << std::endl;
	else {
		std::cout << "The line looks like:" << std::endl;
		print_line(k);
	}

	// task_08 output
	std::cout << std::endl << std::endl;
	std::cout << "Enter two numbers: ";
	int a, b;
	std::cin >> a >> b;
	std::cout << "gcd(" << a << ", " << b << ") = "
		      << gcd(a, b) << std::endl;


	return 0;
}
