/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   dynamic_matrix.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Working with dynamically allocated matrices.
 */

#include <iostream>
#include <iomanip>
#include <ctime>   // std::time()
#include <cstdlib> // std::rand(), std::srand()

const int MAX_ELEM_VAL = 100; // limit for randomly generated numbers
const int NCELLS = 3;   // number of cells for output formatting

// forward declaration, because we want to 'see' it from init_mat
void clear_mat(int**&, size_t);

// mat is a pointer to pointers (will be pointing an array of pointers)
// we take the pointer by reference, because we will redirecting it.
// If not taken by ref, only the local copied pointer will be redirected,
// which will cause the dangling of the pointer in the main.
bool init_mat(int**& mat, size_t n, size_t m) {
    // allocate array of pointers (will be pointing to the rows)
	mat = new (std::nothrow) int* [n];
	// if the allocating was unsuccessful, just return
	if (!mat) return false;
	//
	for (size_t i = 0; i < n; i++) {
		// allocate the current row
		mat[i] = new (std::nothrow) int[m];
        // if unsuccessful, we should go back and
        // free all previously allocated memory
		if (!mat[i]) {
			clear_mat(mat, i - 1);
			return false;
		}
	}
	// if we got here, all the allocations were successful,
	// we proceed with the initialization of each element.
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] = rand() % MAX_ELEM_VAL;
    //
    return true;
}

// just output a matrix's content.
// notice: here we DO NOT have to pass the pointer
// by reference, because we are not going to redirect it.
void print_mat(int** mat, size_t n, size_t m){

    if (!mat) return;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++)
            std::cout << std::setw(NCELLS) << mat[i][j];
		std::cout << std::endl;
	}
}

// frees the allocated memory for a matrix
void clear_mat(int**& mat, size_t n) {

    if (!mat) return;

    // free the memory for each line
	for (size_t i = 0; i < n; i++)
		delete[] mat[i];

	// free the memory for the array of pointers
	delete[] mat;

    // if we don't have this line, we can pass the pointer without ref,
    // but we want to assure that `mat` is in a valid state, it just
    // doesn't point to an allocated memory
	mat = nullptr;
}

int main() {

	srand(time(nullptr));

	size_t n, m;
	int** mat = nullptr;

    std::cout << "Enter n and m (matrix size):" << std::endl;
	std::cin >> n >> m;

	init_mat(mat, n, m);
	print_mat(mat, n, m);
	clear_mat(mat, n);

	return 0;
}
