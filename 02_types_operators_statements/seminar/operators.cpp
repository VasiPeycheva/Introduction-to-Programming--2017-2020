/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   operators.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  C++ basic operators -
 *         assignment, arithmetic,
 *         logical, comparison,
 *         increment/decrement.
 */

#include <iostream>

int main() {

    std::cout << "Assignment operator" << std::endl;
    int ii = 10;
    std::cout << "ii after initialize: " << ii << std::endl;
    ii = 20;
    std::cout << "ii after assigning value of 20: " << ii << std::endl;
    int iii = 30;
    ii = iii;
    std::cout << "ii after assigning the value of the variable iii: " << ii << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "Arithmetic operators" << std::endl;
    int i = 100 + 20;
    std::cout << "i = 100 + 20 = " << i << std::endl;
    int var = i - 10;
    std::cout << "var = i - 10 = " << var << std::endl;
    std::cout << "var * 3 = " << var * 3  << std::endl;

    int a = 19, b = 3;
    int c = a / b;
    int d = a % b;
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "a / b = " << c << std::endl;
    std::cout << "a % b = " << d << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "Comparison operators" << std::endl;
    std::cout << "5 < 3? - " << (5 < 3) << std::endl;
    int h = 10, s = 11;
    std::cout << "h = " << h << " s = " << s << std::endl;
    std::cout << "h equal to s? - " << (h == s) << std::endl;
    std::cout << "h NOT equal to s? - " << (h != s) << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "Logical operators" << std::endl;
    int x = 10;
    std::cout << "x = " << x << std::endl;
    std::cout << "x less than 20 AND bigger than 0? - "
              << ((x < 20) && (x > 0)) << std::endl;

    std::cout << "x is 150 OR x is 10? - "
              << ((x == 150) || (x == 10)) << std::endl;

    std::cout << "NOT (x is 11)? - "
              << !(x == 11) << std::endl;

    // shorter forms:
    int j = 10;
    j += 1;  // is same as:  j = j + 1;
    j -= 10; // is same as:  j = j - 10;
    j *= 4;  // is same as:  j = j * 4;
    j /= 2;  // is same as:  j = j / 2;

    bool flag = true;
    flag |= false; // is same as: flag = flag || false;

    std::cout << std::endl << std::endl;

    std::cout << "Increment/decrement operators" << std::endl;
    j = 20;
    std::cout << "j   = " << j   << std::endl;
    std::cout << "j++ = " << j++ << std::endl;
    std::cout << "j   = " << j   << std::endl;
    std::cout << "++j = " << ++j << std::endl;
    std::cout << "j   = " << j   << std::endl;

    std::cout << "j-- = " << j-- << std::endl;
    std::cout << "j   = " << j   << std::endl;
    std::cout << "--j = " << --j << std::endl;
    std::cout << "j   = " << j   << std::endl;

    return 0;
}
