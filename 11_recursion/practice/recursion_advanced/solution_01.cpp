/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_01.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for recursion task 01 from practice 13.
  */

#include <iostream>

bool push_back(int*& arr, size_t& size, int elem) {

	int* result = new (std::nothrow) int[size + 1];
	if (!result) return false;
	for (size_t i = 0; i < size; i++)
		result[i] = arr[i];

	result[size] = elem;
	delete[] arr;

	arr = result;
	size++;
	return true;
}

bool has_only_odd_digits(int num) {
    // only one digit case
    if (num < 10)
        return (num % 2 != 0);

    // here the recursion call will only be made, if the
    // last digit of num is odd
    return ((num % 10) % 2 != 0) && has_only_odd_digits(num / 10);
}


void filter_numbers_rec(int* arr, size_t arr_size, int*& out_arr, size_t& out_size) {
    // bottom -> no elements left in `arr`
    if (arr_size == 0) return;
    // add the element if it is matching the condition
    if (has_only_odd_digits(*arr)) {
        if(!push_back(out_arr, out_size, *arr)) {
            // clear on push_back error
            delete[] out_arr;
            out_arr = nullptr;
            out_size = 0;
        }
    }
    // move to the next element in `arr`
    filter_numbers_rec(arr + 1, arr_size - 1, out_arr, out_size);
}

int* filter_numbers(int* arr, size_t arr_size, size_t& out_size) {

    int* out_arr = nullptr;
    out_size = 0;

    filter_numbers_rec(arr, arr_size, out_arr, out_size);
    return out_arr;
}

int main() {

    int arr[] = { 11, 23, 57, 42, 71, 53 };

    size_t res_size;
    int* res = filter_numbers(arr, sizeof(arr) / sizeof(int), res_size);

    if (res) {
        for (size_t i = 0; i < res_size; i++)
            std::cout << res[i] << ' ';
        std::cout << std::endl;
    }

    delete[] res;
    return 0;
}





