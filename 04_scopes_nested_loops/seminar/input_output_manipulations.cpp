/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   input_output_manipulations.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Some utilities for I/O formatting.
 *
 */

#include <iostream>
#include <iomanip> // all formatting flags are located here

int main() {

    // the simplest task can be to format a number into different numeral system

    int foo = 42;
    std::cout << "foo: " << foo << "(dec)" << std::endl
              << "foo: 0x" << std::hex << foo << "(hex)" << std::endl
              << "foo: 0"  << std::oct << foo << "(oct)" << std::endl;

    bool bar = false;
    std::cout << "bar: " << std::boolalpha << bar << std::endl;

    int x;
    std::cout << "Enter hexadecimal number: ";
    std::cin >> std::setbase(16) >> x;
    std::cout << "x " << std::dec << x << "(dec)" << std::endl;


    // a common task is to print a fixed number of
    // digits after the decimal comma (point), when
    // working with floating point numbers
    std::cout << std::setprecision(4) // we will format up to 4 digits after the "." -> 3.13121 - 3.1312
              << std::fixed // format exact 4 digits, because when using only setprecision 3.01 will be formatted as 3.01, not 3.0100
              <<  3.13121f
              << std::endl;

    // another example -> format the output into some boxes
    int a = 321;
    std::cout << std::setw(5) // set five boxes [][][][][]
              << std::setfill('0') // set filling character, if not set 321 will be outputted as [][][3][2][1] (two spaces in front)
              << a
              << std::endl;

    // put a string into quotes
    std::cout << std::quoted("test string")
              << " \"test string\"" // we can achieve the same result using escape sequences
              << std::endl;

    return 0;
 }
