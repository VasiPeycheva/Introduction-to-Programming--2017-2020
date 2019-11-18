/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   advanced_functions.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  More about functions - overloading, inline.
 * @see /05_functions/seminar/basic_functions.cpp for simple example
 */

#include <iostream>

// foo is a function with no arguments
void foo() {

    std::cout << "foo() -> none" << std::endl;
}

// here foo takes one - int, so it's an overloaded version of foo
int foo(int x) {

    std::cout << "foo(int) -> int" << std::endl;
    return x;
}

int foo(double x) {

    std::cout << "foo(double) -> int" << std::endl;
    return x;
}

int foo(int x, int y) {

    std::cout << "foo(int, int) -> int" << std::endl;
    return x + y;
}


// here we have two versions of divide ->
// the compiler will call the one, which
// fits the arguments better
double divide(double x, double y) {

    std::cout << "divide(double, double) -> double:" << std::endl;
    return x / y;
}

int divide(int x, int y) {

    std::cout << "divide(int, int) -> int:" << std::endl;
    return x / y;
}


int main() {

    foo();
    foo(42);
    foo(42.0);
    foo(42, 11);

    std::cout << "---------------------------------------" << std::endl;

    std::cout << 5 << " / " << 2 << " by " << divide(5, 2) << std::endl;
    std::cout << 5.0f << " / " << 2.0f << " by " << divide(5.0f, 2.0f) << std::endl;

    return 0;
}
