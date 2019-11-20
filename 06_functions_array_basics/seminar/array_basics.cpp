/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   array_basics.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Some features of fixed size arrays -
 *         initialize, pass to function, indexing.
 */

#include <iostream>

// those C-like arrays will have a fixed size
// which should be known at compile time -
// so consider using constants for those arrays
// size_t is a typedef for unsigned int (possibly unsigned long int)
size_t MAX_N = 10;

// the arrays are always passed by pointer,
// not by copy
void print_array(int arr[], size_t arr_size) {

    for (size_t i = 0; i < arr_size; i++)
        std::cout << arr[i] << " "; // arr[i] in this context means -> read the element on index i from the array
    std::cout << std::endl << std::endl;
}

// the array parameter can have it's size in the [] brackets,
// but that doesn't ensure nothing - the array can be with different size
void print_fixed_arr(int arr[10]) {

    size_t size = sizeof(arr) / sizeof(int); // that won't work, because arr is actually treated as a pointer

    for (size_t i = 0; i < 10; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void modify_array(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++)
        arr[i] += i; // arr[i] in this context means -> write a value into the element on index i from the array
}

int main() {

    // initialize an array with initialization list,
    // when using [] the count of elements will be exactly the
    // number of elements in the list
    int array[] = { 1, 2, 3, 4 };
    int size = sizeof(array) / sizeof(int);
    std::cout << "size of array(in elements): " << size << std::endl;
    std::cout << "array content: " << std::endl;
    print_array(array, size);



    int arr[MAX_N] = {1, 2, }; // all other will be filled automatically with zeroes

    std::cout << "size of arr(in elements): " << MAX_N
              << " calculated: " << sizeof(arr) / sizeof(int)
              << std::endl;
    std::cout << "arr content: " << std::endl;
    print_array(arr, MAX_N);

    modify_array(arr, MAX_N);
    std::cout << "arr content (after modifying): " << std::endl;
    print_array(arr, MAX_N);

    int unin_arr[MAX_N];
    std::cout << "unin_arr content (uninitialized): " << std::endl;
    print_array(unin_arr, MAX_N);


    return 0;
}
