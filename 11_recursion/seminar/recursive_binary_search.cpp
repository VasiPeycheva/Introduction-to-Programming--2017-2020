/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   recursive_binary_search.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  Example implementation of binary search - recursive variant.
 */

#include <iostream>

int binary_search_rec(int* arr, int left, int right, int elem) {
	//there is no such element
	if (left > right)
		return -1;
	//
	// calculate the middle index
	// int mid = (L + R) / 2; // <- a bug source, because L + R can easily overflow
	// solution is
	int mid = left + (right - left) / 2;
	// or even better int mid = L + (((unsigned int)R - (unsigned int)L) >> 1);
	//
	// is the search element on that index?
	if (arr[mid] == elem)
		return mid;
	//
	// grater than the middle element -> search in right
	if (arr[mid] > elem)
		return binary_search_rec(arr, left, mid - 1, elem);
	//
	// less than the middle element -> search in the left
	if (arr[mid] < elem)
		return binary_search_rec(arr, mid + 1, right, elem);
	//
	// won't reach here
	return -1;
}

// wrapper function
int binary_search(int* arr, size_t size, int elem) {

	return binary_search_rec(arr, 0, (int)size - 1, elem);
}

// a variant which uses pointers arithmetic,
// in order to avoid the passing of left and right, but just size
// returns a pointer to the element, if found
int* binary_search_rec_ptr(int* arr, size_t size, int elem) {

	if (size == 0 && arr[size] != elem)
		return nullptr;

	size_t mid = size / 2;

	if (arr[mid] == elem)
		return arr + mid;

	if (arr[mid] < elem)
		return binary_search_rec_ptr(arr + mid + 1, size - (mid + 1), elem);

	if (arr[mid] > elem)
		return binary_search_rec_ptr(arr, mid - 1, elem);
}

int main() {

	int sorted_arr[] = { -121, -9, 5, 11, 23, 48, 70 };
	size_t size = sizeof(sorted_arr) / sizeof(int);

	int searched_el = -9;

	int index = binary_search(sorted_arr, size, searched_el);

    if (index != -1) {
        std::cout << "Found " << searched_el
                  << " at index: " << index
                  << std::endl;
    } else {
        std::cout << searched_el << " not found." << std::endl;
    }

    int* elem_ptr = binary_search_rec_ptr(sorted_arr, size, searched_el);

    if (elem_ptr) {
        std::cout << "Found " << *elem_ptr
                  << " at index: " << (int)(elem_ptr - sorted_arr)
                  << std::endl;
    } else {
        std::cout << searched_el << " not found." << std::endl;
    }

	return 0;
}
