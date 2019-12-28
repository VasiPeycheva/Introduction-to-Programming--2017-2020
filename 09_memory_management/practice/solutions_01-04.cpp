/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   12.2019
  * @brief  Solution for tasks 01-04 from practice 9 (memory management).
  */

#include <iostream>
#include <cmath>

void print(int* arr, size_t size) {

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }

	std::cout << std::endl;
}

// resize an array, return false, if there is no memory available
bool resize(int*& arr, size_t old_size, size_t new_size) {

    int* temp_arr = new (std::nothrow) int[new_size];
    if (!temp_arr) return false;

    size_t size = old_size < new_size ? old_size : new_size;

    for (size_t i = 0; i < size; i++)
        temp_arr[i] = arr[i];

    delete[] arr;
    arr = temp_arr;

    return true;
}

// task_01
void push_back(int*& arr, size_t& size, int elem) {

    if (resize(arr, size, size + 1)) {
        arr[size] = elem;
        ++size;
    }
}

void pop_back(int*& arr, size_t& size) {

    if (resize(arr, size, size - 1))
        --size;
}

// task_02
void insert_at(int*& arr, size_t& size, size_t index, int elem) {

    int* temp_arr = new int[size + 1];
    for (size_t i = 0; i < index; i++)
        temp_arr[i] = arr[i];

    temp_arr[index] = elem;

    for (; index < size; index++)
        temp_arr[index + 1] = arr[index];

    delete[] arr;
    arr = temp_arr;
    size++;
}

void remove_at(int*& arr, size_t& size, size_t index) {

    int* temp_arr = new int[size - 1];
    for (size_t i = 0; i < index; i++)
        temp_arr[i] = arr[i];

    for (; index < size - 1; index++)
        temp_arr[index] = arr[index + 1];

    delete[] arr;
    arr = temp_arr;
    size--;
}

bool is_prime(int n) {

    if (n <= 2)
		return true;

	unsigned long long sq = std::sqrt(n);
	for (unsigned long long i = 2; i <= sq; i++) {
		if (n % i == 0) {
			return false;
		}
	}
    return true;
}

// task_03
void filter_prime(int*& arr, size_t& size) {

    size_t primes = 0;
    for (size_t i = 0; i < size; i++)
        if(is_prime(arr[i]))
            primes++;

    int* temp_arr = new int[primes];
    int temp_cnt = 0;
    for (size_t i = 0; i < size; i++)
        if(is_prime(arr[i]))
            temp_arr[temp_cnt++] = arr[i];

    delete[] arr;
    arr = temp_arr;
    size = primes;
}

// task_04
void unite(int* source_arr, int*& dest_arr, size_t f_size, size_t& s_size) {

    size_t new_size = f_size + s_size;
    int* temp_arr = new int[new_size];
    size_t temp_cnt = 0;
    size_t i = 0, j = 0;
    for (; i < f_size && j < s_size; ) {
        if(source_arr[i] <= dest_arr[j])
            temp_arr[temp_cnt++] = source_arr[i++];
        else
            temp_arr[temp_cnt++] = dest_arr[j++];
    }

    while (i < f_size)
         temp_arr[temp_cnt++] = source_arr[i++];
    while (j < s_size)
        temp_arr[temp_cnt++] = dest_arr[j++];

    delete[] dest_arr;
    dest_arr = temp_arr;
    s_size = new_size;
}

int main() {
    size_t size = 1;
	// allocate the memory we need and let the functions handle it
	// we delete it after we finish using it
    int* arr = new int[size];
    arr[0] = 2;

	std::cout << "The array we will be working with:" << std::endl;
	print(arr, size);

	std::cout << "-----------Task 1-----------" << std::endl;
	std::cout << "Push 3 -> ";
    push_back(arr, size, 3);
	print(arr, size);
	std::cout << "Push 4 -> ";
    push_back(arr, size, 4);
    print(arr, size);
	std::cout << "Pop -> ";
    pop_back(arr, size);
    print(arr, size);

	std::cout << "-----------Task 2-----------" << std::endl;
	std::cout << "Insert 15 at index 2 -> ";
	insert_at(arr, size, 2, 15);
	print(arr, size);
	std::cout << "Remove element at index 2 -> ";
	remove_at(arr, size, 2);
	print(arr, size);

	std::cout << "-----------Task 3-----------" << std::endl;
	push_back(arr, size, 5);
	push_back(arr, size, 11);
	push_back(arr, size, 17);
	push_back(arr, size, 10);
	print(arr, size);
	std::cout << "Filter into:" << std::endl;
	filter_prime(arr, size);
	print(arr, size);

	std::cout << "-----------Task 4-----------" << std::endl;
	size_t sec_size = 2;
	int* sec_arr = new int[sec_size];
	sec_arr[0] = 5;
	sec_arr[1] = 20;
	std::cout << "First array:" << std::endl;
	print(arr, size);
	std::cout << "Second array:" << std::endl;
	print(sec_arr, sec_size);
	unite(arr, sec_arr, size, sec_size);
	std::cout << "Result array:" << std::endl;
	print(sec_arr, sec_size);

	// free the memory we allocated
	delete[] arr;
	delete[] sec_arr;
	return 0;
}
