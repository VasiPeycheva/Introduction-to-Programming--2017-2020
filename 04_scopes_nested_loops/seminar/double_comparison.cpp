/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   double_comparison.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  An example, which shows how to (how to not)
 *         work with floating point numbers in C++.
 *
 * @note   The results may vary on different platforms.
 */

#include <iostream>
#include <iomanip>
#include <cmath> // std::abs

const double EPS = 0.001f;
const double SMALLER_EPS = 0.000000001f;

int main() {

    double num = 1.1f; // just 1.1 number

    // lets calculate it as a sum
    // starting from 0.0 when we add 11 time 0.1, the result
    // will be 1.1, won't it?
    double step = 0.1f;
    double sum = 0.0f;
    for (int i = 0; i < 11; i++)
        sum += step;

    // again 1.1, but as a multiplication
    double mul = step * 11.0f;

    // print 20 digits after the floating point
    std::cout << std::setprecision(20) << std::fixed;

    std::cout << "num: " << num << std::endl;
    std::cout << "num as a sum: " << sum << std::endl;
    std::cout << "num as a multiplication: " << mul << std::endl << std::endl;

    // the "num" and "sum" should be equal - both 1.1
    // but are they?
    if (num == sum) {
        std::cout << "num == sum" << std::endl;
    } else {
        std::cout << "Lol?! num != sum" << std::endl;
    }

    // so, one of the correct ways to compare floating point numbers
    // is by a tolerance. We say they are equal, if they are close enough,
    // in the terms of mathematics.
    // EPS (epsilon controls how precise the compression to be ("how many digits to be taken into consideration")
    if (std::abs(num - sum) < EPS) {
        std::cout << "num == sum with EPS(" << EPS << ')' << std::endl;
    } else {
        std::cout << "lol" << std::endl;
    }

    // if we want to see if one floating point number is smaller than other:
    if (num - sum > SMALLER_EPS) {
        std::cout << "num > sum with EPS(" << SMALLER_EPS << ')' << std::endl;
    }

    return 0;
}
