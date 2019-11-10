/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   basic_functions.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Functions basics - arguments, parameters, return types.
 */

#include <iostream>

// when can have a function which does not return a value,
// and has no parameters
void print_msg() {

    std::cout << "Just a test massage..." << std::endl;
}

// simple function, which takes an integer
// an returns the same value
int id(int x) {

    return x;
}

// a function with has two parameters int-s
// and returns their multiplication
int mul(int a, int b) {

    return a * b;
}

int sum_mul(int a, int b) {
    // we can call other functions inside a given function
    return a + b + mul(a, b);
}

// the arguments of a function are passed by value ->
// an inner copy of their value is created for the function's
// purposes
int inc_with_ten(int x) {
    // we add 10 to "ours" x, not the one, with which the function has been called
    x = x + 10;
    return x;
}


int main() {

    std::cout << 100 << "=? " << id(100) << std::endl;

    int x= 23, y = 11;
    std::cout << x << " * " << y << " = " << mul(x, y) << std::endl;

    std::cout << x << " + " << y << " + "
              << x << " * " << y << " = " << sum_mul(x, y) << std::endl;


    std::cout << "adding 10 to my_var(";
    int my_var = 42;
    std::cout << my_var << ") 5times: " << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << inc_with_ten(my_var) << std::endl;
    std::cout << "my_var in main:" << my_var << std::endl;

    std::cout << "(" << x << " + 10) * "
              << "(" << y << " + 10) = "
              << mul(inc_with_ten(x), inc_with_ten(y))
              << std::endl;

    return 0;
}
