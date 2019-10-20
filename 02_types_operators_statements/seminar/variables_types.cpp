/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   variables_types.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  A program's basic parts -
 *         comments, literals,
 *         variables, constants.
 */

// We are going to use some basic I/O functionality,
// that is why we need to include the standard C++
// I/O library - iostream, from where we have:
// - std::cin  (read  (get) information from the standard input [keyboard for now])
// - std::cout (write (put) information to the standard output [display, console])
// - std::endl (newline symbol(s))
// The "including" is done via the preprocessor directive #include
#include <iostream>

// this is a single line comment

/* And
   this
   is
   a
   multi-line
   comment
*/

// this is a constant -> read below (on line - 119)
const int MAX_N = 100;

// "main" is a special function ->
// it is the entry point of our application
int main() {

// literals are notations for representing a fixed value in our source code
    std::cout << "----------------Literals---------------" << std::endl;
    std::cout << "A string in double quotes is a literal\n";
    std::cout << 100141221 << std::endl; // a simple decimal number is a literal
    std::cout << 0xFF << std::endl;      // a hexadecimal number
    std::cout << 0xA  << std::endl;      // yet another one
    std::cout << 0750 << std::endl;      // an octal number
    std::cout << 0b10101 << std::endl;   // a binary number
    std::cout << 'a' << std::endl;       // a symbol between single quotes is a literal


// variables are used to store and manipulate a program's data
// C++ is strongly typed language - each variable is from a fixed type.
    std::cout << "-----------Types of variables-----------" << std::endl;

    int a; // declaring a variable with name "a", basically saying - there is a such variable
    std::cout << "The value of uninitialized variable can be strange: " << a << std::endl;

    // integer type - holds an natural number.
    int i = 10; // defining a variable with name "b" and value 10
    std::cout << "Variable \"i\" (integer) has a value of: " << i
              << " and size " << sizeof(i) << "(bytes)" << std::endl;

    // boolean type - holds a logical value (true or false)
    bool b = true;
    std::cout << "Variable \"b\" (boolean) has a value of: " << b
              << " and size " << sizeof(b) << "(bytes)" << std::endl;

    // character type - hold a symbol (but the symbols are also represented as numbers)
    char c = 'f';
    std::cout << "Variable \"c\" (character) has a value of: " << c
              << " and size " << sizeof(c) << "(bytes)" << std::endl;
    char c_dec = 65; // a symbol with decimal value of 65
    std::cout << "Variable \"c_dec\" (character) has a value of: " << c_dec
              << " and size " << sizeof(c_dec) << "(bytes)" << std::endl;

    // you should know that there are some special characters
    char new_line_char = '\n';
    char tab_char = '\t';
    std::cout << "That is a" << tab_char << "tab indent"
              << new_line_char << "And this text is on a new line" << std::endl;


    // short integer (<= integer) - smaller numbers
    short int si = 245;
    std::cout << "Variable \"si\" (short integer) has a value of: " << si
              << " and size " << sizeof(si) << "(bytes)" << std::endl;

    // long integer (>= integer) - bigger numbers
    long int li = 12345678L; // <- we can use "L" to show that the literal is a long number
    std::cout << "Variable \"li\" (long integer) has a value of: " << li
              << " and size " << sizeof(li) << "(bytes)" << std::endl;

    // long integer (>= integer) - bigger numbers
    long long int lli = 123456789LL; // <- we can use "LL" to show that the literal is a long long number
    std::cout << "Variable \"lli\" (long long integer) has a value of: " << lli
              << " and size " << sizeof(lli) << "(bytes)" << std::endl;

    // "floating point" number
    float f = 123.012f; // <- we can use "f" to show that the literal is a float number
    std::cout << "Variable \"f\" (float) has a value of: " << f
              << " and size " << sizeof(f) << "(bytes)" << std::endl;

    // "floating point" number with better precision
    double d = 123.0123456f; // <- we can use "f" to show that the literal is a float/double number
    std::cout << "Variable \"d\" (double) has a value of: " << d
              << " and size " << sizeof(d) << "(bytes)" << std::endl;

    // we can use "const" modifier to tell that a variable won't change it's value
    //const int ci; //!< error -> constants should always be initialized
    const int ci = 230;
    // int const ci = 230; // same as above

    // we can use "unsigned" modifier to tell that a variable will have only positive values
    unsigned short int usi = 10;

    // we can use both modifiers:
    const unsigned long long int thats_a_very_long_type = 1234ULL; // <- ULL -> unsigned long long literal

    // a constants could be really useful when the same value
    // is used across many different computations (expressions),
    // but first take a look at "operators" example :)
    std::cout << "Global constant MAX_N: "<< MAX_N << std::endl;

    // our program should return a code to the operating system
    // 0 is a common value for "successful execution".
    return 0;
}
