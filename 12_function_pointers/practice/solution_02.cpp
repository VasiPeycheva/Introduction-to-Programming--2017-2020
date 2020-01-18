/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_02.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for function pointers task 02 from practice 14.
  */

#include<iostream>

typedef int(*math_func_fptr)(int);

int id(int x) {

	return x;
}

int square(int x) {

	return x * x;
}

bool check_interval(int beg, int end, math_func_fptr mf) {

	for (int i = beg; i <= end - 1; i++)
		for (int j = i + 1; j <= end; j++)
			if (mf(i) == mf(j))
				return true;

	return false;
}

int main() {


	std::cout << "Checking id(x) in the interval [-10; 10]:" << std::endl;
	std::cout << (check_interval(-10, 10, id) ?
		          "There are two points with the same function value." :
                  "There aren't such points!")
		      << std::endl
		      << std::endl;

    std::cout << "Checking square(x) in the interval [-10; 10]:" << std::endl;
	std::cout << (check_interval(-10, 10, square) ?
		          "There are two points with the same function value." :
                  "There aren't such points!")
		      << std::endl;

	return 0;
}
