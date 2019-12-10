/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   pointers_basics.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Example syntax and usage of pointers.
 */

#include <iostream>

// forward declaration, see below for details.
void swap_with_ptr(int* a, int* b);

int main() {
    // each variable has:
    // - type
    // - name
    // - value
    // - address (where in the memory it is)
    // - storage type (type of memory)
    int x = 11;
    std::cout << "x: " << x << " at "
              << &x << std::endl; // with operator& we can extract the address of a variable

    // pointers are special type of variables, their values are addresses of other variables
    // here p_x is a pointer to a integer
    int* p_x = &x; // p_x points to x (p_x has a value - address of the variable x)

    // pointers are also variables, so &p_x gives us the address of the pointer itself
    // p_x is the value of the pointer -> the address of the pointed object
    // *p_x extracts the value of the pointed object (dereferencing)
    std::cout << "p_x: " << p_x << " at "
              << &p_x << " pointed value: " << *p_x << std::endl;
    std::cout << std::endl;
    // we can change the value of the pointed variable though the pointer
    *p_x = 23;

    std::cout << "x: " << x << " at "
              << &x << std::endl;

    std::cout << "p_x: " << p_x << " at "
              << &p_x << " pointed value: " << *p_x << std::endl;
    std::cout << std::endl;
    //

    // we have a special value (NULL/nullptr), which has the meaning of
    // "this pointer currently points to NOTHING". (NULL is C-style, nullptr - C++).
    int* p = nullptr; // NULL
    //!!! trying to get the value of a pointer, which points to NULL, will result in program's termination.
    // tryme:
    //  std::cout << p << ' ' <<  *p;
    int* p_i; // we can declare a pointer without initialization, we DO NOT know where it is pointing.
    p_i = &x; // p_i now points to x
    int* p2;
    p2 = p_i; // p_i now points where p1 points
    //

    // all pointers have the same size in bytes. Enough to contain the largest possible address value.
    // The size actually depends on the platform.
    char c;
    double d;

    char* p_c   = &c;
    double* d_p = &d;
    std::cout << "size of pointer to char:   " << sizeof(p_c)
              << "bytes (which is " << sizeof(p_c) * 8 << "bits)"
              << std::endl;
    std::cout << "size of pointer to int:    " << sizeof(p_i)
              << "bytes (which is " << sizeof(p_i) * 8 << "bits)"
              << std::endl;
    std::cout << "size of pointer to double: " << sizeof(d_p)
              << "bytes (which is " << sizeof(d_p) * 8 << "bits)"
              << std::endl;
    std::cout << std::endl;
    //

    // usage of the swap function with pointers
    int z = 10, y = 27;
    std::cout << "z and y before swapping them: " << z << ' ' << y << std::endl;
    swap_with_ptr(&z, &y);
    std::cout << "z and y  after swapping them: " << z << ' ' << y << std::endl;
    //


    // all possible combination of const and *
    int* ptr_to_int;             // normal pointer to integer
    const int* ptr_to_const_int; // pointer to a constant integer (we can't change the pointed value!)
    // same as int const* p;

    // constant pointer to integer.
    // we CANNOT redirect the pointer, but we CAN change the pointed value.
    int* const const_ptr_to_int = ptr_to_int;

    const int c_int = 10;
    // constant pointer to a constant integer.
    // The most restricted, NOTHING can be changed.
    const int* const const_ptr_to_const_int = &c_int;

    return 0;
}


// As we know all function parameters are passed by copy.
// That is why the standard version won't work - it will only swap the LOCAL COPIES.
// But we can achieve the swap using pointers.
// `a` is a pointer to the first variable, `b` to the other.
void swap_with_ptr(int* a, int* b) {
    // `t` is a normal integer
    int t = *a; // assign `t` the value of the pointed by `a` variable
    *a = *b;    // assign the pointed by `a` variable the value of the pointed by `b`
    *b = t;     // assign the pointed by `b` variable the value of `t`
}
