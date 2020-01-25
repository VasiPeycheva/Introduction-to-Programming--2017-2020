/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   maze.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  A simple console game, with two modes - interactive & automatic.
 */

#include <cstdio>   // std::printf()
#include <cstdlib>  // std::rand(), std::srand()
#include <ctime>    // std::time()

// include out custom header
#include "helpers.h"

int main() {

	/* initialize the random generator */
	std::srand(std::time(nullptr));
	/* create the maze and target coordinates */
	int target_x, target_y;
	init_maze(target_x, target_y);

    /* read the running mode */
    std::puts("Supported modes:");
	std::puts("0 - automatic");
	std::puts("1 - interactive");
	std::printf("Enter mode: ");

	int mode;
	if ((scanf("%d", &mode) != 1) ||
        (mode != 0 && mode != 1)) {
        std::puts("Invalid input!");
        return 1;
	}

    /* output the starting maze */
    print_maze(true);

	if (mode == 0) {
        /* run the algorithm */
        if (dfs_find(START_X, START_Y, target_x, target_y))
            std::puts("there is a path!");
        else
            std::puts("there isn't a path!");
	} else {
	    /* start the interactive game */
        play_interactive(START_X, START_Y);
	}

	return 0;
}
