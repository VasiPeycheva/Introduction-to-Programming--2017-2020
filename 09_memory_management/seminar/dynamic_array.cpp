/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   dynamic_array.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Working with dynamically allocated arrays.
 */

#include <iostream>
#include <ctime>   // std::time()
#include <cstdlib> // std::rand(), std::srand()

const size_t  MAX_SIZE = 10; // array max size
const int MAX_ELEM_VAL = 100; // maximum value for filling arrays

// initialize an array with random values
void init_arr(int* p_arr, size_t size) {

    if (p_arr == nullptr) return;

    for (size_t i = 0; i < size; i++)
        p_arr[i] = std::rand() % (MAX_ELEM_VAL + 1);
}

// simply output an array content
void print_arr(int* p_arr, size_t size) {

    if (p_arr == nullptr) return;

    std::cout << "The array starts at: " << p_arr << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << p_arr[i] << ' ';
    std::cout << std::endl;
}

// doubles the memory allocated for an array pointed by p_arr
// we take the pointer by reference, because we will redirecting it.
// If not taken by ref, only the local copied pointer will be redirected,
// which will cause the dangling of the pointer in the main.
void realloc_arr(int*& p_arr, size_t& size) {

    if (p_arr == nullptr) return;

    // allocated new memory
    int* new_mem = new (std::nothrow) int[size * 2];
    if (!new_mem) { // check if the allocation was successful
        std::cout << "Reallocating have failed." << std::endl;
        return;
    }
    //
    // copy all old elements
    for (size_t i = 0; i < size; i++)
        new_mem[i] = p_arr[i];
    //
    // free the old array
    delete[] p_arr;
    // redirect the given pointer to the new memory
    p_arr = new_mem;
    // double the logical size
    size *= 2;
    //
}


int main() {

    // trying to allocate too much memory
    int* p_arr = new (std::nothrow) int[212110210211L];
    if (p_arr == nullptr) {
        std::cout << "Not enough memory..." << std::endl;
    }
    //

    srand(time(nullptr));

    size_t size;
    std::cout << "Enter base size for the array:";
    std::cin >> size;

    int* pd_arr = new (std::nothrow) int[size];
    if (pd_arr == nullptr) {
        std::cout << "Not enough memory..." << std::endl;
        return 1;
    }

    init_arr(pd_arr, size);
    std::cout << "Allocated array with random elements:" << std::endl;
    print_arr(pd_arr, size);


    realloc_arr(pd_arr, size);
    std::cout << "Reallocated array with random elements and uninitialized ones:"
              << std::endl;
    print_arr(pd_arr, size);

    // don't forget to free the allocated memory.
    delete[] pd_arr;

    return 0;
}
