/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   bitwise_operators.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Some common tricks with bitwise operations.
 *         Also, shows the idea of over/under-flows.
 */

#include <iostream>
#include <climits> // defines constants line INT_MAX - the maximum value an int can have

const unsigned char BITS_PER_BYTE = CHAR_BIT; // each byte have eight bits.

int main() {

    // an overflow example
    int a = INT_MAX;
    std::cout << "INT_MAX     = " << a     << std::endl
              << "INT_MAX + 1 = " << a + 1 << std::endl;

    // and an underflow one
    int b = INT_MIN;
    std::cout << "INT_MIN     = " << b     << std::endl
              << "INT_MIN - 1 = " << b - 1 << std::endl;
    //- Why is this happening?
    //- Because of the "in-memory" representation of the numbers.

    std::cout << "-----------------------" << std::endl;

    // how to generate a value, such as unsigned char max?
    std::cout << "UCHAR_MAX = " << UCHAR_MAX << std::endl;
    // an unsigned char is actually a byte ->
    // each byte has 8bits, so the maximum value it can
    // have is when all of those bits are on ->
    // 0b1111111, lets add 1 to that number,
    // we got 0b100000000, which is exactly 2 ^ 8.
    // to compute the maximum value we need, we have to
    // remove the added 1 -> (2 ^ 8 - 1)
    // 1 << 8 is "one shifted eight times to the left",
    // which is 2 ^ 8
    std::cout << "UCHAR_MAX = " << (1 << BITS_PER_BYTE) - 1
              << "(bitwise calculated)" << std::endl;

    // lets apply the same trick with unsigned int
    std::cout << "UINT_MAX = " << UINT_MAX << std::endl;
    unsigned int ui = (1 << (sizeof(unsigned int) * BITS_PER_BYTE)) - 1;
    std::cout << "UINT_MAX = " << ui
              << "(bitwise calculated)" << std::endl;

    std::cout << "-----------------------" << std::endl;

    // a common bitwise task is to extract a given bit
    // from a number, for example the third bit
    unsigned int bb = 0b00110101;
    // to do so, we need a "mask" - a special value, created to fit the task
    unsigned mask = 1 << 2;
    // and a bitwise operation - "and" in this case
    std::cout << "Third bit of 0b00110101 is: "
              << ((bb & mask) ? 1 : 0) << std::endl; // the parenthesis are needed here

    // another task could be to set a bit on a given position
    unsigned int bar = 0b00111011;
    // again we need a mask
    mask = 1 << 2; // 0b00000100
    // set the bit using the mask and "or" bitwise operation
    bar |= mask; // bar = bar | mask;
    std::cout << "0b00110101 after setting the third bit to 1: "
              << bar << std::endl;
    // lets have a simple check
    std::cout << bar << " =? "
              << ((1 << 6) - 1) << std::endl;

    // other possible usage - extract a byte from a 4-byte number
    unsigned int num = 0xFF0AC0;
    // we are going to extract the middle byte
    // |00|FF|0A|C0
    // our mask is |00|00|FF|00
    // the result should be right-shifted with one byte,
    std::cout << "The hex number 0xFF0AC0, has a second byte with decimal value of: "
              << ((num & 0xFF00) >> 8) << std::endl;

    std::cout << "Let's apply bitwise XOR to 42 and 11, just for fun."
              << std::endl << "result: " << (42 ^ 11) << std::endl;

    return 0;
}
