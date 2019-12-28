/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   recursion_basics.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Example about recursions.
 */

/*
 Linear recursion - the function calls itself once only (in an execution branch).
 Tree recursion   - more than one call.
 Indirect recursion - A calls B, B calls C, C calls A.
*/

#include <iostream>

/* Tail recursion (subclass of linear rec) <=> simulate loop */
void loop_simulate_recursion(int i) {

    if (i == 10) return;
    std::cout << "Rec call: " << i << std::endl;
    loop_simulate_recursion(i + 1);
}


/* Linear recursion */
int fact(int x) {

    if (x == 0) return 1;

    return x * fact(x - 1);
}

/* Tree recursion */
int fib(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

/* Indirect recursion */
bool is_odd(int x);

bool is_even(int x) {

    if (x == 0) return true;

    return is_odd(x - 1);
}

bool is_odd(int x) {

    return !is_even(x);
}

int main() {


    loop_simulate_recursion(0);

    std::cout << fact(5) << std::endl;
    std::cout << fib(6) << std::endl;
    std::cout << std::boolalpha << is_even(25);

    return 0;
}
