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
const int N_ELEMS = 10;

// the arrays are always passed by pointer,
// not by copy
void print_array(int arr[], int arr_size) {

    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " "; // arr[i] in this context means -> read the element on index i from the array
    std::cout << std::endl << std::endl;
}

// the array parameter can have it's size in the [] brackets,
// but that doesn't ensure nothing - the array can be with different size
void print_fixed_arr(int arr[N_ELEMS]) {

    int size = sizeof(arr) / sizeof(int); // that won't work, because arr is actually treated as a pointer

    for (int i = 0; i < N_ELEMS; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void modify_array(int arr[], int size) {

    for (int i = 0; i < size; i++)
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



    int arr[N_ELEMS] = {1, 2, }; // all other will be filled automatically with zeroes

    std::cout << "size of arr(in elements): " << N_ELEMS
              << " calculated: " << sizeof(arr) / sizeof(int)
              << std::endl;
    std::cout << "arr content: " << std::endl;
    print_array(arr, N_ELEMS);

    modify_array(arr, N_ELEMS);
    std::cout << "arr content (after modifying): " << std::endl;
    print_array(arr, N_ELEMS);

    int unin_arr[N_ELEMS];
    std::cout << "unin_arr content (uninitialized): " << std::endl;
    print_array(unin_arr, N_ELEMS);


    return 0;
}
