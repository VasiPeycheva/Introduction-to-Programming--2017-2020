/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   variables_types.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  A simple program
 *         that uses a conditional statement
 *         if / else.
 * @see block_diagram
 */

#include <iostream>

int main() {

    // read a number
    int x;
    std::cin >> x;

    // check if it is an even or odd
    if (x % 2 == 0) {
        // if even -> divide it by 10
        x /= 10;
    } else {
        // if odd
        if (x > 100) {
            // odd and grater than 100
            x++;
        } else {
            // odd and less than 100
            x--;
        }
    }

    std::cout << x << std::endl;
}
