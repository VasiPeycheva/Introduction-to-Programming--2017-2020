/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_07.cpp
  * @author Ivan Filipov
  * @date   11.2019
  * @brief  Solution for task 7 from practice 4.
  */

#include <iostream>
#include <iomanip>

const int TRIANGLE_MAX = 7;
const int SAND_GLASS_MAX_SIZE = 8;

int main() {

    // print the first figure
    for (int row = 1; row <= TRIANGLE_MAX; row++) {
        for (int col = 1; col <= row; col++) {
            std::cout << std::setw(2) << col;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    // print second figure
    for (int row = 0; row < TRIANGLE_MAX; row++) {
        for (int spaces = 0; spaces < row; spaces++) {
            std::cout << std::setw(2) << " ";
        }
        for (int col = 1; col <= TRIANGLE_MAX - row; col++) {
            std::cout << std::setw(2) << col;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    // print the third figure
    int max_num = SAND_GLASS_MAX_SIZE / 2;
    bool mid_printed = false;
    for (int row = 0; row < SAND_GLASS_MAX_SIZE; row++) {
        // revert logic, if below the center
        int row_num = std::min(SAND_GLASS_MAX_SIZE - row - 1, row);

        // don't print the mid line twice
        if (row_num == max_num - 1 && !mid_printed)
            mid_printed = true;
        else if (row_num == max_num - 1 && mid_printed)
            continue;

        // white-spaces in front
        for (int spaces = 0; spaces < row_num; spaces++) {
            std::cout << std::setw(2) << " ";
        }
        // numbers print in-order
        for (int num = row_num + 1; num <= max_num; num++) {
            std::cout << std::setw(2) << num;
        }
        // print numbers reverse order
        for (int num = max_num; num > row_num; num--) {
            std::cout << std::setw(2) << num;
        }

        // white-spaces in back
        for (int spaces = 0; spaces < row_num; spaces++) {
            std::cout << std::setw(2) << " ";
        }
        std::cout << std::endl;
    }

	return 0;
}
