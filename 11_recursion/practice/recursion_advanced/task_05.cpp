/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_05.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for recursion tasks from practice 11.
  */

#include <iostream>
#include <iomanip> // setw

const size_t MAXN = 100;
const size_t NUM_TESTS = 10;

// the focus it not on dynamic memory, so ..
unsigned int matrix[MAXN][MAXN] = { 0 };

void print_matrix(size_t k) {

	for (size_t i = 0; i < k; i++) {
		for (size_t j = 0; j < k; j++)
			std::cout << std::setw(3)
				<< matrix[i][j];

		std::cout << std::endl;
	}

	std::cout << std::endl
		<< std::endl
		<< std::endl
		<< std::endl;
}

void fill_matrix(const size_t k, size_t it, size_t cur_size) {

	// only one cell to go
	if (it == k * k) {

		matrix[k / 2][k / 2] = it;
		return;
	}

	// begin index
	size_t start_cell = (k - cur_size) / 2;
	// end index
	size_t border = start_cell + cur_size - 1;

	// down fill
	for (size_t i = 0; i < cur_size; i++)
		matrix[start_cell + i][start_cell] = it++;

	// right fill ->
	for (size_t i = 1; i < cur_size; i++)
		matrix[border][start_cell+ i] = it++;

	// up fill
	for (size_t i = border - 1; i > start_cell; i--)
		matrix[i][border] = it++;

	// left fill <-
	for (size_t i = border; i > start_cell; i--)
		matrix[start_cell][i] = it++;

	
	if (it <= k * k)
		fill_matrix(k, it, cur_size - 2);

}

int main() {

	unsigned int k = 1;

	while (k <= NUM_TESTS) {

		fill_matrix(k, 1, k);

		print_matrix(k);

		k++;
	}

	return 0;
}