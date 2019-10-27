/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   basic_loops.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  How to control the flow of
 *         execution with loops.
 */

#include <iostream>

int main() {

    // see-the-matrix loop
    while (true) { // endless loop
        //std::cout << "a?#b1&c"; // commenting out is up to you :)
        break; // stop the loop (remove that line in the endless loop)
    }

    int i = 10;
    std::cout << "from 10 to 0 with while loop:" << std::endl;
    while (i > 0) {
        std::cout << i << " ";
        --i;
    }

    std::cout << std::endl;
    std::cout << "than from " << i << " to 0 with while loop:" << std::endl;
    while (i > 0) {
        std::cout << i << " ";
        --i;
    }

    std::cout << "than from " << i << " to 0 with do-while loop:" << std::endl;
    do {
        std::cout << i << " ";
        --i;
    } while (i > 0);

    std::cout << std::endl;
    std::cout << "Enter n (> 0):";
    unsigned int n;
    std::cin >> n;
    std::cout << "All natural numbers to n: " << std::endl;
    for (unsigned int i = 0; i < n; i++) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << "All even natural numbers to n: " << std::endl;
    for (unsigned int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            continue; // make step forward, without executing the code below
        }
        std::cout << i << " ";

        /* which is the same as:
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
        */
    }

    std::cout << std::endl;
    // !!! please, don't write stuff like the example above -
    // there is much smarter approach
    for (unsigned int i = 0; i < n; i += 2) { // make the step 2
        std::cout << i << " ";
    }

    return 0;
}
