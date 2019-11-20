/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   searching_sorting.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Algorithms for:
 *         sorting   - Selection sort
 *         searching - linear & binary search
 */

#include <iostream>
#include <ctime>   // std::time()
#include <cstdlib> // std::rand(), std::srand()

const size_t  MAX_SIZE = 10; // array max size
const int     TEST_CNT = 10; // number of tests
const int MAX_ELEM_VAL = 100; // maximum value for filling arrays

// initialize an array with random values
void init_arr(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++)
        arr[i] = std::rand() % (MAX_ELEM_VAL + 1); // rand() returns a big number and we map it to [0, 100]
}

// simply output an array content
void print_arr(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

// find the minimum element in an array [what is it and what is it's index]
void min_arr(int arr[], size_t size) {

    int min_val = arr[0]; // let's assume that arr[0] is the smallest
    int min_ind = 0;      // and it's index is 0

    // go through all other elements
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min_val) { // if there is a smaller element than the current minimum
            min_val = arr[i];   // update the current minimum
            min_ind = i;        // and it's index
        }
    }

    // output results
    std::cout << "Min elem: " << min_val
              << " at pos: "  << min_ind
              << std::endl;
}

// sorting a given array,
// using Selection sort algorithm
void sort_arr(int arr[], size_t size) {
    // the strategy here is quite simple:
    // just logically divide the array into two parts
    // sorted and unsorted
    // on each step: find the minimal element from the unsorted part
    // and add it as maximal element to the sorted part
    int min_val;
    int min_ind;

    for (size_t i = 0; i < size - 1; i++) {
        // current minimal
        min_val = arr[i];
        min_ind = i;
        // search "unsorted" part for smaller element
        // than the current minimal
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < min_val) {
                min_val = arr[j]; // update the current min
                min_ind = j;
            }
        }
        // swap only if there is a smaller element
        if (min_ind != (int)i) {
            int t  = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = t;
        }
    }
}


// search for a given element in an array,
// using linear search algorithm
// return index if found,
// -1 if element is not presenting
int linear_search(int arr[], size_t size, int searched_el) {

    // try each element sequently
    for (size_t i = 0; i < size; i++)
        if (arr[i] == searched_el)
            return i;
    // not fount
    return -1;
}

// search for a given element in an array,
// using binary search algorithm
// return index if found,
// -1 if element is not presenting
int binary_search(int arr[], size_t size, int searched_el) {

    int left  = 0;        // sub-array start index (from the whole array)
    int right = size - 1; // sub-array end   index (from the whole array)
    // which is the mid index and the value of the element in the mid position
    int mid_ind, mid_val;
    // until our borders aren't swapped
    while (left <= right) {
        // get the middle index
        mid_ind = (left + right) / 2;
        // get the middle value
        mid_val = arr[mid_ind];
        // check if the searched one is this one
        if (mid_val == searched_el) {
            return mid_ind;
        }
        // if the searched element is smaller than the mid one,
        // we should search in the left half, so we move the right boarder
        if (mid_val > searched_el) {
            right = mid_ind - 1;
        }
        // opposite of above
        if (mid_val < searched_el) {
            left = mid_ind + 1;
        }
    }

    // not found
    return -1;
}

// run some searches for random elements
// compares linear and binary search results
void run_searching_tests(int arr[], size_t size) {

    int searched_el = 0;
    int ls, bs;
    for (int i = 1; i < TEST_CNT; i++) {
        searched_el = rand() % (MAX_ELEM_VAL + 1);
        std::cout << "searching for "  << searched_el << ':' << std::endl;
        std::cout << "linear search: " << (ls = linear_search(arr, size, searched_el));
        std::cout << std::endl;
        std::cout << "binary search: " << (bs = binary_search(arr, size, searched_el));
        std::cout << std::endl;

        if (bs != ls) std::cout << "Test FAILED!!!" << std::endl;

        // stop on each test
        std::cout << "Press any key + Enter:";
        char c;
        std::cin >> c;
    }
}

int main() {

    // seed the random generator with the current time
    std::srand(std::time(0));

    int arr[MAX_SIZE];

    std::cout << "Randomly initialized array: " << std::endl;
    init_arr(arr, MAX_SIZE);
    print_arr(arr, MAX_SIZE);
    std::cout << std::endl;

    std::cout << "It's minimal element: " << std::endl;
    min_arr(arr, MAX_SIZE);
    std::cout << std::endl;

    // min_arr(arr, MAX_SIZE - 5); // find the min element within the first MAX_SIZE - 5 elements

    std::cout << "The array after sorting: " << std::endl;
    sort_arr(arr, MAX_SIZE);
    print_arr(arr, MAX_SIZE);
    std::cout << std::endl;

    run_searching_tests(arr, MAX_SIZE);

    return 0;
}
