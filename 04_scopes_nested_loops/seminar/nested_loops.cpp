/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   nested_loops.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  An example, which prints nicely the representative
 *         part of the ASCII table, using nested loops.
 */

#include <iostream>
#include <iomanip>

const int SYMBOLS_PER_ROW = 3;  // on each row we are going to print 3 ASCII symbols
const int SYMBOLS_PER_COL = 32; // we will have 32 symbols in each column

int main() {

    for (int rows = 0; rows < SYMBOLS_PER_COL; rows++) { // <- outer loop, on each of it's steps, the inter loop will be fully executed
        for (int cols = 0; cols < SYMBOLS_PER_ROW; cols++) { // <- inner loop
                // decimal representation of that symbol (+1, to skip the first 32 character, which are system specific)
                int decimal = rows + ((cols + 1) * SYMBOLS_PER_COL);
                // symbol representation -> just save the decimal number as a symbol
                char symbol = decimal;
                std::cout << std::setw(3) << decimal << "->"
                          << '\'' << symbol << '\'' << "| ";
        }
        // on each step of the outer loop, print a new line (so the rows are on new line each)
        std::cout << std::endl;
    }
}
