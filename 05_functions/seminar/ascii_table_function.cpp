/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   ascii_table_function.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Printing the ASCII table, with some
 *         helper functions
 * @see nested_loops.cpp
 * @see https://bg.wikipedia.org/wiki/ASCII
 */

#include <iostream>
#include <iomanip>

const int SYMBOLS_PER_ROW = 4;  // on each row we are going to print 4 ASCII symbols
const int SYMBOLS_PER_COL = 32; // we will have 32 symbols in each column


bool is_special_symbol(char c) {

    if (c >= 0 && c <= 31)
        return true;

    return c == 127;
}


void output_normal_char(char c, int dec) {

    std::cout << std::setw(3) << dec << "->"
              << '\'' << c << '\'' << "| ";
}

void output_special_char(char c, int dec) {

    std::cout << std::setw(3) << dec << "->";
    switch(c) {
    case 0:  std::cout << "NUL"; break;
    case 1:  std::cout << "SOH"; break;
    case 2:  std::cout << "STX"; break;
    case 3:  std::cout << "ETX"; break;
    case 4:  std::cout << "EOT"; break;
    case 5:  std::cout << "ENQ"; break;
    case 6:  std::cout << "ACK"; break;
    case 7:  std::cout << "BEL"; break;
    case 8:  std::cout << "BS "; break;
    case 9:  std::cout << "HT "; break;
    case 10: std::cout << "LF "; break;
    case 11: std::cout << "VT "; break;
    case 12: std::cout << "FF "; break;
    case 13: std::cout << "CR "; break;
    case 14: std::cout << "SO "; break;
    case 15: std::cout << "SI "; break;
    case 16: std::cout << "DLE"; break;
    case 17: std::cout << "DC1"; break;
    case 18: std::cout << "DC2"; break;
    case 19: std::cout << "DC3"; break;
    case 20: std::cout << "DC4"; break;
    case 21: std::cout << "NAK"; break;
    case 22: std::cout << "SYN"; break;
    case 23: std::cout << "ETB"; break;
    case 24: std::cout << "CAN"; break;
    case 25: std::cout << "EM "; break;
    case 26: std::cout << "SUB"; break;
    case 27: std::cout << "ESC"; break;
    case 28: std::cout << "FS "; break;
    case 29: std::cout << "GS "; break;
    case 30: std::cout << "RS "; break;
    case 31: std::cout << "US "; break;

    case 127: std::cout << "DEL"; break;

    default: std::cout << "LOL"; // won't get here
    }

    std::cout << "| ";
}

// a function that prints the ASCII table to stdout
void print_ascii_table() {

    for (int rows = 0; rows < SYMBOLS_PER_COL; rows++) {
        for (int cols = 0; cols < SYMBOLS_PER_ROW; cols++) {
                int decimal = rows + (cols * SYMBOLS_PER_COL);
                char symbol = decimal;

                if (is_special_symbol(symbol))
                    output_special_char(symbol, decimal);
                else
                    output_normal_char(symbol, decimal);
        }
        std::cout << std::endl;
    }
}

int main() {

    print_ascii_table();

    return 0;
}
