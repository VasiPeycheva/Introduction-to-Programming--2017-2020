/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   helpers.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  A C++ source file, which contains our app logic implementation.
 */

#include <cstdio>   // std::printf()
#include <cstdlib>  // std::rand(), std::srand()
#include <ctime>    // std::time()

#ifdef _WIN32 // on Windows, define/include those:
    #include <conio.h>
    #include <windows.h>
    #define KEY_UP    72
    #define KEY_LEFT  75
    #define KEY_RIGHT 77
    #define KEY_DOWN  80
    #define ESC       224

    #define get_char()     getch()
    #define clear_screen() \
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 })

#else // on *NIX those:
    #include <termios.h>
    #define KEY_UP    'A'
    #define KEY_LEFT  'D'
    #define KEY_RIGHT 'C'
    #define KEY_DOWN  'B'
    #define ESC       '\033'

    #define get_char()     getchar()
    #define clear_screen() printf("\033[0;0H")
#endif // _WIN32

// include our own declaration
#include "helpers.h"


//@{
/// some constants for easier cell recognition
#define LAVA   -2 //!< lava
#define UNVGND -1 //!< unvisited ground
// --- 0 to 3 are occupied by direction symbols ---
#define CUR_POS 4 //!< player's current position
#define VGND    5 //!< visited by not in the path
#define TARGET  6 //!< marker for target
#define REACHED_TARGET 7 //!< marker for reached target
#define DEATH_PLAYER   8 //!< marker for death player
//@}

//@{
/// some characters for beautiful output
#define LAVA_SYM   '#'
#define TARGET_SYM '$'
#define WIN_SYM    '*'
#define UNVGND_SYM ' '
#define VGND_SYM   '-'
#define PLAYER_SYM 'P'
#define DEATH_PLAYER_SYM 'X'
//@}

#define ROWS 4 //!< maze rows count
#define COLS 4 //!< maze columns count

/// the maze itself
int maze[ROWS][COLS];

/// number of directions
#define N_DIR 4
//@{
/// difference by x and y for each direction
int diff_x[] = { 0, 1,  0, -1 };
int diff_y[] = { 1, 0, -1,  0 };
char dir_sym[] = { '>', 'v', '<', '^' };
//@}

//@{
/// constants for arrows input and direction mapping
enum {
    LEFT_DIR  = 0,
    DOWN_DIR  = 1,
    RIGHT_DIR = 2,
    UP_DIR    = 3
};
//@}


// ----- per file helper function -------

/// simple delay function in C - style
static void delay(unsigned int secs) {

	time_t ret_time = time(nullptr) + secs;
	while (time(nullptr) < ret_time)
		;
}

/// print separator between rows
static void place_row_separator() {

    for (size_t j = 0; j < COLS * 2; j++)
        std::printf("--");
    std::putchar('\n');
}

/// check if a point is in the maze or outside
static bool are_valid_coords(int x, int y) {

	if (x < 0 || y < 0)
		return false;

	if (x >= ROWS || y >= COLS)
		return false;

	return true;
}

#ifndef _WIN32
/// setups the input to be non-blocking on *NIX
static void setup_input() {
    // some Linux dark magic :)
    struct termios initial_settings, new_settings;
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 0;

    tcsetattr(0, TCSANOW, &new_settings);
}
#endif // _WIN32

/// read arrow input
static int get_dir_from_input() {
#ifndef _WIN32
    static bool setup_done = false;
    if (!setup_done) {
        setup_input();
        setup_done = true;
    }
#endif // _WIN32

    int n = get_char();
    if (n == EOF) return EOF;

    if (n == ESC) { // if the first value is esc
#ifndef _WIN32
        get_char(); // skip the [
#endif // _WIN32
        switch (get_char()) { // the real value
        case KEY_UP:
            // code for arrow up
            return UP_DIR;
        case KEY_DOWN:
            // code for arrow down
            return DOWN_DIR;
        case KEY_LEFT:
            // code for arrow right
            return RIGHT_DIR;
        case KEY_RIGHT:
            // code for arrow left
            return LEFT_DIR;
        default:
            return EOF;
        }
    }

    return EOF;
}



// ---- implementations of the header's declared functions


void init_maze(int& target_x, int& target_y) {

	for (size_t i = 0; i < ROWS; i++)
		for (size_t j = 0; j < COLS; j++)
			maze[i][j] = ((std::rand() % 30) < 20) - 2; // results in -2 or -1
    // generate target's coordinates (somewhere below the main diagonal)
    target_x = (ROWS / 2) + (std::rand() % ROWS / 2);
    target_y = (COLS / 2) + (std::rand() % COLS / 2);
	// mark the target reachable
	maze[target_x][target_y] = TARGET;
}

void print_maze(bool is_iteractive) {

    if (is_iteractive) {
        clear_screen();
    }
    place_row_separator();

	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			switch (maze[i][j]) {
			case LAVA:
				std::printf("%2c", LAVA_SYM);
				break;
			case TARGET:
				std::printf("%2c", TARGET_SYM);
				break;
			case UNVGND:
				std::printf("%2c", UNVGND_SYM);
				break;
			case VGND:
				std::printf("%2c", VGND_SYM);
				break;
            case CUR_POS:
				std::printf("%2c", PLAYER_SYM);
				break;
            case REACHED_TARGET:
				std::printf("%2c", WIN_SYM);
				break;
            case DEATH_PLAYER:
                std::printf("%2c", DEATH_PLAYER_SYM);
                break;
			default:
			    std::printf("%2c", dir_sym[maze[i][j]]);
			}
			std::printf(" |");
		}
		std::putchar('\n');
		place_row_separator();
	}

    if (!is_iteractive) {
        std::printf("\n\n\n");
    }

	delay(1);
}


bool dfs_find(int x, int y, int target_x, int target_y) {

	// checks if we have reached the target
	if ((x == target_x) && (y == target_y)) {
		maze[x][y] = REACHED_TARGET;
		print_maze();
		return true;
	}

    // marking this cell as visited
	maze[x][y] = CUR_POS;
	// current maze look
	print_maze();

	// where to make the next step
	int new_x, new_y;
	// trying all directions
	for (int dir = 0; dir < N_DIR; dir++) {
		// calc next step
		new_x = x + diff_x[dir];
		new_y = y + diff_y[dir];
		// if we can get there
		if (are_valid_coords(new_x, new_y) &&
			((maze[new_x][new_y] == UNVGND) ||
			(maze[new_x][new_y]  == TARGET))) {
			// try to find path from there
			maze[x][y] = dir; // mark the direction
			if (dfs_find(new_x, new_y, target_x, target_y)) {
                // the step has led to a solution
				return true;
			} else {
                // if this step wasn't winning - cut that path
                maze[x][y] = CUR_POS;
				maze[new_x][new_y] = VGND;
				print_maze();
			}
		}
	}
    // all possible directions were iterated, unsuccessfully
	return false;
}

void play_interactive(int x, int y) {

    int cur_x = x, cur_y = y;
    maze[cur_x][cur_y] = CUR_POS; // mark the player
    print_maze(true);

    while (true) {
        // get the direction from the input
        int dir = get_dir_from_input();
        if (dir == EOF) continue;

        int new_x = cur_x + diff_x[dir];
		int new_y = cur_y + diff_y[dir];

        // check game conditions:
        if (!are_valid_coords(new_x, new_y))
            continue; // on wrong direction, just skip the move

        if (maze[new_x][new_y] == LAVA) {
            // end game condition - death player
            maze[cur_x][cur_y] = UNVGND;
            maze[new_x][new_y] = DEATH_PLAYER;
            print_maze(true);
            std::puts("You are DEATH! Pay more attention next time, the princess won't rescue herself!");
            break;
        }

        if (maze[new_x][new_y] == TARGET) {
            // end game condition - player won
            maze[cur_x][cur_y] = UNVGND;
            maze[new_x][new_y] = REACHED_TARGET;
            print_maze(true);
            std::puts("You have successfully rescued the princess!");
            break;
        }

        maze[cur_x][cur_y] = UNVGND;
        maze[new_x][new_y] = CUR_POS;
        cur_x = new_x;
        cur_y = new_y;
        print_maze(true);
    }
}
