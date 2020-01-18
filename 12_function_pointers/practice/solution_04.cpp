/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_04.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for function pointers task 04 from practice 14.
  */

#include <iostream>
#include <cstdlib> // std::qsort
#include <cstring>

void print_arr(int* arr_ptr, size_t size) {

	for (size_t i = 0; i < size; i++)
		std::cout << arr_ptr[i] << ' ';

	std::cout << std::endl;
}

int greater(const void* rhs, const void* lhs) {

    int rhs_v = *((int*)rhs);
    int lhs_v = *((int*)lhs);

    return rhs_v - lhs_v;
}

int str_cmp(const void* rhs, const void* lhs) {

    return strcmp((*(const char**)rhs), (*(const char**)lhs));
}

int main() {

    int given_arr[] = { 1, 15, 23, 11, -125, 45, -9, 911 };
	size_t size = sizeof(given_arr) / sizeof(int);


    std::cout << "given array:" << std::endl;
	print_arr(given_arr, size);

	std::qsort(given_arr, size, sizeof(int), greater);
	std::cout << "\nAfter sorting with greater:" << std::endl;
	print_arr(given_arr, size);
	std::cout << std::endl;


    const char* str_arr[] = { "again", "Great", "FMI", "Make" };
    size = sizeof(str_arr) / sizeof(const char*);
    std::cout << "Some strings: " << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << str_arr[i] << std::endl;
    std::cout << std::endl << std::endl;

    std::qsort(str_arr, size, sizeof(const char*), str_cmp);
    std::cout << "After sorting them: " << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << str_arr[i] << std::endl;
    std::cout << std::endl;
}


