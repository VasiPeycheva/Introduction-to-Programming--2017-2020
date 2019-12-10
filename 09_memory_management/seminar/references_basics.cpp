/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   references_basics.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Example syntax and usage of references.
 */

#include <iostream>

// forward declaration, see below for details.
void swap_with_ref(int& a, int& b);

int main() {
    // each variable has:
    // - type
    // - name
    // - value
    // - address (where in the memory it is)
    // - storage type (type of memory)
    int x = 11;
    std::cout << "x: " << x << " at "
              << &x << std::endl;

    // References have the meaning of (different name for an existing object).
    // references are syntax sugar for constant pointer (pointers, which CANNOT be redirected).
    // but with a few key differences:
    // - there is NOT a NULL value for references.
    // - a reference SHOULD always be initialized (there is no such rule for pointers).
    // - a reference CANNOT be redirected (it is a different name for a single object).
    int& x_ref = x; // x_ref is a reference to x

    std::cout << "x_ref: " << x_ref << " at "
              << &x_ref << std::endl;
    std::cout << std::endl;

    x_ref = 23; // change the value though the reference

    std::cout << "x: " << x << " at "
              << &x << std::endl;
    std::cout << "x_ref: " << x_ref << " at "
              << &x_ref << std::endl;
    std::cout << std::endl;

    /*
        There is no standard rule how
        references should be implemented and
        what their sizes are.
    */


    // we can have a reference to constant variable,
    // which means we CANNOT change the referred value.
    const int& c_x_ref = x;


    // usage of the swap function with references
    int z = 10, y = 27;
    std::cout << "z and y before swapping them: " << z << ' ' << y << std::endl;
    swap_with_ref(z, y);
    std::cout << "z and y  after swapping them: " << z << ' ' << y << std::endl;
    //

    // References are extremely useful for:
    // avoiding copies, write functions which change their parameters and etc.
    // But they are much more limited compared to pointers.

    return 0;
}

// unlike the pointers, the syntax here is much simpler.
void swap_with_ref(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}
