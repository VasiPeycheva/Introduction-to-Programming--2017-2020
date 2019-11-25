/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for function tasks from practice 8.
  */

#include <iostream>
#include <iomanip> // std::setw()
#include <cmath>   // std::log10()

// constants for maximum dimensions of the matrix
const size_t MAX_ROWS = 16;
const size_t MAX_COLS = 16;


// helper function for finding in how much cells the largest number
// in a given matrix can be printed
int find_max_cell_size(int mat[][MAX_COLS], size_t m, size_t n) {

    // set the first element as default
	int max_element = mat[0][0];

	for (size_t row = 0; row < m; row++) {
		for (size_t col = 0; col < n; col++) {
			if (max_element < mat[row][col]) {	// if we find bigger than current maximum
				max_element = mat[row][col];	// we take it's value
			}
		}
	}
    // return the number of digits that maximum number have, +1, if we have negative values
    return ((int)log10(max_element) + 1) + 1;
}

// task_01
// Filling the matrix from standard input(keyboard)
void fill_matrix(int mat[][MAX_COLS], size_t m, size_t n) {

	for (size_t row = 0; row < m; row++)
		for (size_t col = 0; col < n; col++)
			std::cin >> mat[row][col];
}

// Print the matrix to standard output(console)
void print_matrix(int mat[][MAX_COLS], size_t m, size_t n) {

    int cell_size = find_max_cell_size(mat, m, n);
	for (size_t row = 0; row < m; row++) {
		for (size_t col = 0; col < n; col++)
			std::cout << std::setw(cell_size) << mat[row][col] << ' ';
		std::cout << std::endl; // to separate the rows of the matrix
	}
}
// ------------------------

// task_02
// Find minimum element in the matrix
int min_matrix_element(int mat[][MAX_COLS], size_t m, size_t n) {

	// set the first element as default
	int min_element = mat[0][0];

	for (size_t row = 0; row < m; row++) {
		for (size_t col = 0; col < n; col++) {
			if (min_element > mat[row][col]) {	// if we find smaller than current minimum
				min_element = mat[row][col];	// we take it's value
			}
		}
	}

	return min_element; // return the value of the minimum
}
// ------------------------

// task_03
// Multiply every element by scalar
void multiply_with_scalar(int mat[][MAX_COLS], size_t m, size_t n, int scalar) {

	for (size_t row = 0; row < m; row++)
		for (size_t col = 0; col < n; col++)
			mat[row][col] *= scalar;
}
// ------------------------

// task_04
// Sum of two matrices with same size
void sum_matrices(int mat_1[MAX_ROWS][MAX_COLS], int mat_2[MAX_ROWS][MAX_COLS],
	size_t m, size_t n) {

	for (size_t row = 0; row < m; row++)
		for (size_t col = 0; col < n; col++)
			mat_1[row][col] += mat_2[row][col];
}
// ------------------------

// task_05
// Print the frame of matrix
// FirstSolution
void print_frame(int mat[][MAX_COLS], size_t m, size_t n) {

    int cell_size = find_max_cell_size(mat, m, n);
	for (size_t row = 0; row < m; row++) {
		for (size_t col = 0; col < n; col++)
			if ((row == 0 || row == m - 1) || (col == 0 || col == n - 1)) {
				std::cout << std::setw(cell_size) << mat[row][col] << ' ';
			} else {
				std::cout << std::setw(cell_size + 1) << ' ';
			}
		std::cout << std::endl;
	}
}

// Second solution
void print_frame_2(int mat[][MAX_COLS], size_t m, size_t n) {

    int cell_size = find_max_cell_size(mat, m, n);
	// print first row
	for (size_t col = 0; col < n; col++) {
		std::cout << std::setw(cell_size) << mat[0][col] << ' ';
	}

	std::cout << std::endl;
	// print next n-2
	for (size_t row = 1; row < m - 1; row++)
	{
		std::cout << std::setw(cell_size) << mat[row][0] << ' ';
		for (size_t col = 1; col < n - 1; col++) {
			std::cout << std::setw(cell_size + 1) << ' ';
		}

		std::cout << std::setw(cell_size) << mat[row][n - 1] << ' ';
		std::cout << std::endl;
	}

	// print last row
	for (size_t col = 0; col < n; col++) {
		std::cout << std::setw(cell_size) << mat[m - 1][col] << ' ';
	}
	std::cout << std::endl;
}
// ------------------------

// task_06
// Print Diagonals of square matrix
// It won't work if it is not square
void print_diagonals(int mat[][MAX_COLS], size_t n) {

    int cell_size = find_max_cell_size(mat, n, n);
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < n; col++) {
			if (row == col || row + col == n - 1) {
				std::cout << std::setw(cell_size) << mat[row][col] << ' ';
			} else {
				std::cout << std::setw(cell_size + 1) << ' ';
			}
		}
		std::cout << std::endl;
	}
}
// ------------------------

// task_07
// The function finds the wanted result
// and then directly prints it to the standard output
void below_and_above_the_diagonal(int mat[][MAX_COLS], size_t rows, size_t cols) {

	int sum_above = 0;
	int cnt_odd_below = 0;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			// above the main diagonal
			if (i < j) {
				sum_above += mat[i][j];
			}
			// not else !!! because if we have else it will be i <= j
			// which will contain the main diagonal

			// below the main diagonal
			if ((i > j) && (mat[i][j] % 2 != 0)) { // and the element is odd
				cnt_odd_below++;
			}
		}
	}

	std::cout << sum_above * cnt_odd_below;
}
// ------------------------

// task_08
// Simple function that checks if 'elem' is
// the smallest elem in a given array 'arr' with size 'size'
bool is_max_in_row(int elem, int arr[], size_t size) {

	for (size_t i = 0; i < size; i++) {
		if (arr[i] > elem) {
			return false;
		}
	}
	return true;
}

// A function that prints the saddle element of a given matrix
// The function checks each point of the matrix
// but there is a better algorithm : http://www.geeksforgeeks.org/saddle-point-matrix/
void saddle_point(int mat[][MAX_ROWS], size_t rows, size_t cols) {

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
				// we can pass the whole row
				// as a function argument
			if (is_max_in_row(mat[i][j], mat[i], cols)) {
				// checking the column here,
				// because we can't pass it to a function
				bool is_min_in_col = true;
				for (size_t k = 0; k < rows && is_min_in_col; k++) {
					if (mat[k][j] < mat[i][j]) {
						is_min_in_col = false;
					}
				}
				// we have found the saddle point
				if (is_min_in_col) {
					std::cout << "The saddle point is : matrix("
						      << i << ", " << j << ") = " << mat[i][j] << std::endl;
					return; // there can be only one saddle
				}
			}
		}
	}

	// if we reach here there isn't a saddle point
	std::cout << "There isn't a saddle point in the given matrix!!!" << std::endl;
}
// ------------------------

int main() {

	unsigned int m, n;
	int scalar;
	std::cout << "Enter number of rows: ";
	std::cin  >> m;
	std::cout << "Enter number of columns: ";
	std::cin  >> n;

	if (m >= MAX_ROWS || n >= MAX_COLS) {
		std::cout << "Error: can't handle such a big matrix!" << std::endl;
		return -1; // here we are exiting our program with error code -1
	}

	int matrix[MAX_ROWS][MAX_COLS];		// allocating enough memory
	int matrix_2[MAX_ROWS][MAX_COLS];	// for task of summing matrices

	std::cout << "\n-----------Task 1-----------" << std::endl;
	std::cout << "Enter matrix's data: " << std::endl;
	fill_matrix(matrix, m, n);
	std::cout << std::endl;
	print_matrix(matrix, m, n);

	std::cout << "-----------Task 2-----------" << std::endl;
	std::cout << "Minimal element of the matrix : " << min_matrix_element(matrix, m, n) << '\n';

	std::cout << "-----------Task 3-----------" << std::endl;
	std::cout << "Enter a scalar: ";
	std::cin  >> scalar;

	multiply_with_scalar(matrix, m, n, scalar);
	std::cout << "Multiply with scalar: " << scalar << std::endl;
	print_matrix(matrix, m, n);

	std::cout << "-----------Task 4-----------" << std::endl;
	std::cout << "Enter second matrix data: " << std::endl;
	fill_matrix(matrix_2, m, n);

	std::cout << "First matrix + Second matrix =" << std::endl;
	sum_matrices(matrix, matrix_2, m, n);
	print_matrix(matrix, m, n);

	std::cout << "-----------Task 5-----------" << std::endl;
	print_frame(matrix, m, n);
	std::cout << std::endl;
	print_frame_2(matrix, m, n);

	std::cout << "-----------Task 6-----------" << std::endl;
	std::cout << "Printing only matrix's diagonals: " << std::endl;
	print_diagonals(matrix, n);

	std::cout << "-----------Task 7-----------" << std::endl;
	std::cout << "The sum of the element above the main diagonal,\nmultiplied by"
			     " the count of odd element below the main diagonal is: ";
	below_and_above_the_diagonal(matrix, m, n); // only calling the function, it will print the result
	std::cout << std::endl;

	// The function will find the saddle point
	// If such point exists and print it's
	// indexes and value to the standard output
	std::cout << "-----------Task 8-----------" << std::endl;
	saddle_point(matrix, m, n);

	return 0;
}
