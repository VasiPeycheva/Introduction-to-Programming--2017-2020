/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_03.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for function pointers task 03 from practice 14.
  */

#include <iostream>

typedef bool(*cmp_fptr)(int, int);

void print_arr(int* arr_ptr, size_t size) {

	for (size_t i = 0; i < size; i++)
		std::cout << arr_ptr[i] << ' ';

	std::cout << std::endl;
}

bool greater(int x, int y) {

	return x > y;
}

bool less(int x, int y) {

	return x < y;
}

// the third argument is the function
// which we will be using to compare the array's elements
void selection_sort(int* arr, size_t size, cmp_fptr cmp) {

	size_t index;
	for (size_t i = 0; i < size - 1; i++) {
		index = i;
		for (size_t j = i + 1; j < size; j++)
			if (cmp(arr[index], arr[j])) // the slight difference is here
				index = j;
		std::swap(arr[i], arr[index]);
	}
}

int main() {

	int given_arr[] = { 1, 15, 23, 11, -125, 45, -9, 911 };
	size_t size = sizeof(given_arr) / sizeof(int);

	std::cout << "given array:" << std::endl;
	print_arr(given_arr, size);

	selection_sort(given_arr, size, less);
	std::cout << "\nAfter sorting with lesser:" << std::endl;
	print_arr(given_arr, size);

	selection_sort(given_arr, size, greater);
	std::cout << "\nAfter sorting with greater:" << std::endl;
	print_arr(given_arr, size);

	return 0;
}
