/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_03.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for task 3 from advanced_string tasks (practice 11).
  */

#include <iostream>

const int MAX = 16;

// fill the crossword puzzle with words
void fill(char cross[][MAX], int size) {

	for (size_t i = 0; i < size - 1 ; i++)
		std::cin >> cross[i];
}

void print(char cross[][MAX], int size) {

	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size; j++)
			std::cout << cross[i][j];

		std::cout << '\n';
	}
}

// check if given row and column are filled with the same elements
bool check_word(char cross[][MAX], int size, int row, int col) {

	for (size_t i = 0; i < size -1; i++)
		if (cross[row][i] != cross[i][col])
			return false;

	return true;
}

// check how many rows and columns match
int check_cross(char cross[][MAX], int size) {

	int result = 0;
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - 1; j++)
			if (check_word(cross, size, i, j))
				result++;
	}

	return result;
}

int main() {

	char cross[MAX][MAX];
	int size;
	std::cin >> size;
	fill(cross, size);

	std::cout << "\nThe cross looks: \n";
	print(cross, size);
	std::cout << "\nYou have: " << check_cross(cross, size) << " matching words! \n";

	return 0;
}
