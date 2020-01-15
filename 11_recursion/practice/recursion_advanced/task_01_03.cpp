/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_01_03.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for recursion tasks from practice 11.
  */

#include <iostream>

typedef bool(*fptr)(int); 

const size_t MAXN = 100;

unsigned int addends[MAXN];

void print(size_t len) {

	for (size_t i = 1; i < len; i++)
		std::cout << addends[i] << '+' ;

	std::cout << addends[len] << '\n';
}

void create_sum(unsigned int n, size_t pos) {

	if (n == 0) {

		print(pos - 1);
		return;
	}

	for (unsigned int k = n; k >= 1; k--) {

		addends[pos] = k;

		if (addends[pos] <= addends[pos - 1])
			create_sum(n - k, pos + 1);
	}
}

void push_back(int*& arr, size_t& size, int elem) {
	
	int* result = new int[size + 1];
	for (size_t i = 0; i < size; i++)
		result[i] = arr[i];

	result[size] = elem;
	delete[] arr;

	arr = result;
	size++;
}

bool is_even(int number) {
	return number % 2 == 0;
}

void print_arr(int* arr, size_t size) {

	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	
	std::cout << std::endl;
}

void filter_numbers(int*& arr, size_t& size, fptr pred) {

	int* result_arr = nullptr;
	size_t new_size = 0;

	for (size_t i = 0; i < size; ++i) {
		if (fptr(arr[i])) {
			push_back(result_arr, new_size, arr[i]);
			new_size++;
		}
	}
	delete[] arr;
	
	arr = result_arr;
	size = new_size;
}

int main() {

	unsigned int n = 7;

	addends[0] = n + 1;

	create_sum(n, 1);

	size_t size = 10;
	int* arr = new int[size];
	for(int i = 0; i < size; ++i) {
		arr[i] = i*i;
	}

	filter_numbers(arr, size, is_even);

	delete[] arr;
	return 0;
}
