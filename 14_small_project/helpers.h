/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   helpers.h
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  A header file, which contains some function declarations and constants.
 */

// include guards, read about them in the seminar #13
#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#define START_X 0 //!< player's start x coordinate
#define START_Y 0 //!< player's start y coordinate

// Notice: here we have only DECLARATIONs of functions

/// initialize maze's cells
/// with 66% change -> available cell (UNVGND)
/// with 33% change -> unavailable cell (LAVA)
/// @param[out] target_x: where is the target (x coordinate)
/// @param[out] target_y: where is the target (y coordinate)
void init_maze(int& target_x, int& target_y);


/// simply outputs the maze content
void print_maze(bool is_iteractive = false);

/**
 * @brief Runs recursively DFS into the generated maze.
 * @param[in] x: current x coordinate
 * @param[in] y: current y coordinate
 * @param[in] target_x: target x coordinate
 * @param[in] target_y: target y coordinate
 */
bool dfs_find(int x, int y, int target_x, int target_y);

/// Let the user control the game
void play_interactive(int x, int y);

#endif // HELPERS_H_INCLUDED
