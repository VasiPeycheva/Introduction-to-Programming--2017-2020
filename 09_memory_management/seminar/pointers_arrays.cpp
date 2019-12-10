/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   pointer_arrays.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Example about relationship between pointers and arrays.
 */

#include <iostream>

/* forward declarations read below */
void print_arr(int* arr, size_t size);

int main() {

    // we know that an array is a sequence of variables
    // placed continuously (as a block) into the memory
    int arr[] = { 1, 2, 3, 4 };
    size_t arr_size = sizeof(arr) / sizeof(int);

    for (size_t i = 0; i < arr_size; i++)
        std::cout << "arr[" << i << "] = " << arr[i]
                  << " placed at: " << &arr[i] << std::endl;

    std::cout << std::endl;
    std::cout << "the array begins at: " << arr; // the name of the array is actually an address
    std::cout << std::endl;

    // so we can direct a pointer to the array's beginning:
    int* p  = arr;     // p points to the beginning of arr
    int* p1 = &arr[0]; // p1, also, why?

    std::cout << "p points to: " << p
              << " and the pointed value is: " << *p
              << std::endl;

    // there are operations with pointers called "pointers arithmetic"
    p = p + 3; // when adding/removing an number to/from a pointer
               // we actually move it with that number multiplied by pointer's type
               // addresses forward/backward.
    // so here we have moved `p` with 3 * sizeof(int) addresses forward, guess what is placed at that address?
    std::cout << "After moving - p points to: " << p
              << " and the pointed value is: " << *p
              << std::endl;
    std::cout << std::endl;

    // now we can understand what is the compiler does, when we use [] operator on an array:
    std::cout << "arr[3] = " << arr[3] << std::endl;
    std::cout << "*(arr + 3) = " << *(arr + 3) << std::endl;
    // arr[i] <=> *(arr + i)
    std::cout << std::endl;


    // same can be done with matrices, because as we know,
    // they are a block of arrays with fixed size, placed one after
    // another in the memory
    int mat[2][3] = {
        { 1, 2, 3 },
        { 11, 5, 6 }
    };
    // that is equivalent to int mat[2 * 3];


    int* mat_base = &mat[0][0];
    std::cout << "The matrix is allocated at: " << mat << std::endl;
    std::cout << "&mat[0][0] is: " << mat_base << std::endl;

    // We can compute the address of an element of the matrix
    // using the rows and columns. For this we use the following formula:
    // mat[i][j] = base_address + [(i x no_of_cols + j) x size_of_data_type]
    std::cout << "mat[1][2] = " << mat[1][2] << std::endl;
    //int* m_base = (int*)mat; // could also do the trick, mat is int (*)[3]
    std::cout << "*(mat_base + 1 * 3 + 2) = " << *(mat_base + (1 * 3 + 2)) << std::endl;

    // or also:
    std::cout << "*(*(mat + 1) + 2) = " << *(*(mat + 1) + 2) << std::endl;
    // here mat is of type (*)[3], so (mat + 1) gives a pointer to first row, dereferencing it
    // we got an address - where that row starts, than adding 2 (as in 1D array).

    // DO NOT write code like above - always prefer [] syntax!
    std::cout << std::endl;

    std::cout << "Printing array with function using pointer: " << std::endl;
    print_arr(arr, arr_size);
    std::cout << std::endl;

    std::cout << "Printing matrix with function using pointer: " << std::endl;
    print_arr(mat_base, 2 * 3);

    return 0;
}

// we can print array or matrix, or even more D object, by just passing
// it's beginning and type as a pointer of that type
void print_arr(int* arr, size_t size) {

    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    // or like an absolute hacker:
    std::cout << "As a hacker:" << std::endl;
    int i = 0;
    while (i < size) {
    // here we first make *arr -> get currently point value,
    // than arr = arr + 1 -> move pointer with one position
        std::cout << *arr++ << ' ';
        i++;
    }
    std::cout << std::endl;
}
