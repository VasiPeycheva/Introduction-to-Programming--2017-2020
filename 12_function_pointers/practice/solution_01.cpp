/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_01.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for function pointers task 01 from practice 14.
  */

#include <iostream>

typedef bool(*pr_fptr)(int);

bool is_even(int x) {

    return x % 2 == 0;
}

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

int* filter_numbers(int* arr, size_t arr_size, size_t& out_size, pr_fptr pr) {

    int* out_arr = nullptr;
    out_size = 0;

    for (size_t i = 0; i < arr_size; i++) {
        if (pr(arr[i])) {
            if(!push_back(out_arr, out_size, arr[i])) {
                // clear on push_back error
                delete[] out_arr;
                out_arr = nullptr;
                out_size = 0;
            }
        }
    }

    return out_arr;
}

int main() {

    int arr[] = { 10, 23, 57, 42, 71 };

    size_t res_size;
    int* res = filter_numbers(arr, sizeof(arr) / sizeof(int), res_size, is_even);

    if (res) {
        for (size_t i = 0; i < res_size; i++)
            std::cout << res[i] << ' ';
        std::cout << std::endl;
    }

    delete[] res;
    return 0;
}
