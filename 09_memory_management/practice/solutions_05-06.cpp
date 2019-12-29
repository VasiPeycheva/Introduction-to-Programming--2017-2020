/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   solutions_05-06.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Solution for tasks 05-06 from practice 9 (memory management).
 */

#include <iostream>
#include <iomanip>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>   // std::time()
#include <cmath>  // std::log10()

const int MAX_ELEM_VAL = 100; // limit for randomly generated numbers
const int NCELLS = 3;         // number of cells for output formatting
const int MIN_ROWS_CNT = 4;   // minimal number of rows our matrix can have
const int MIN_COLS_CNT = 2;   // minimal number of rows our matrix can have
const int MAX_ROWS_CNT = 8;   // maximum number of rows our matrix can have
const int MAX_COLS_CNT = 8;   // maximum number of cols our matrix can have

// ----- general helpers -----

// generate a random number in [minimal; maximal]
size_t get_rand_num_in_interval(int minimal, int maximal) {

    int mmin = std::min(minimal, maximal);
    int mmax = std::max(minimal, maximal);

    return (size_t)(mmin + (rand() % (mmax - mmin)));
}

// forward declaration
void clear_mat(int**& mat, size_t& rows_cnt, int*& rows_lens_arr);

// fill a single row with random elements
void init_row(int* row, size_t row_size) {

    for (size_t i = 0; i < row_size; i++)
        row[i] = rand() % MAX_ELEM_VAL;
}

// params:
// - matrix - will hold the saw matrix
// - rows_cnt - how many rows will be there
// - rows_lens_arr - array with length of each row
bool create_random_saw_matrix(int**& mat, size_t& rows_cnt, int*& rows_lens_arr) {
    // random number of rows
    rows_cnt = get_rand_num_in_interval(MIN_ROWS_CNT, MAX_ROWS_CNT);
    // allocate the array for sizes
    rows_lens_arr = new (std::nothrow) int[rows_cnt];
    if (!rows_lens_arr) {
        rows_cnt = 0;
        return false;
    }

    // allocate array of pointers (will be pointing to the rows)
	mat = new (std::nothrow) int* [rows_cnt];
	// if the allocating was unsuccessful, just return
	if (!mat) {
        // clear all previously allocated memory
        delete[] rows_lens_arr;
        rows_lens_arr = nullptr;
        rows_cnt = 0;
        return false;
	}
	//
	for (size_t i = 0; i < rows_cnt; i++) {
	    // generate the size
	    rows_lens_arr[i] = get_rand_num_in_interval(MIN_COLS_CNT, MAX_COLS_CNT);;
		// allocate the current row
		mat[i] = new (std::nothrow) int[rows_lens_arr[i]];
        // if unsuccessful, we should go back and
        // free all previously allocated memory
		if (!mat[i]) {
            size_t rows_cnt = i - 1;
			clear_mat(mat, rows_cnt, rows_lens_arr);
			return false;
		}
	}
	// if we got here, all the allocations were successful,
	// we proceed with the initialization of each row.
	for (size_t i = 0; i < rows_cnt; i++)
		init_row(mat[i], rows_lens_arr[i]);
    //
    return true;
}

// just output a single row
void print_row(int* row, size_t row_size) {

    for (size_t i = 0; i < row_size; i++)
        std::cout << std::setw(NCELLS) << row[i];
}

// just output a matrix's content.
void print_mat(int** mat, size_t rows_cnt, int* rows_lens_arr){

    if (!mat || !rows_lens_arr) return;

    for (size_t i = 0; i < rows_cnt; i++) {
		print_row(mat[i], rows_lens_arr[i]);
        std::cout << std::endl;
    }
}

// frees the allocated memory for a matrix
void clear_mat(int**& mat, size_t& rows_cnt, int*& rows_lens_arr) {

    delete[] rows_lens_arr;
    rows_lens_arr = nullptr;

    if (!mat) return;

    // free the memory for each line
	for (size_t i = 0; i < rows_cnt; i++)
		delete[] mat[i];

	// free the memory for the array of pointers
	delete[] mat;

    // if we don't have this line, we can pass the pointer without ref,
    // but we want to assure that `mat` is in a valid state, it just
    // doesn't point to an allocated memory
	mat = nullptr;
	rows_cnt = 0;
}

// END ----- general helpers -----

// ----- task 05 -----
bool is_row_with_odd_sum(int* row, size_t row_size) {

    if (!row) return false;

    int sum = 0;
    for (size_t i = 0; i < row_size; i++)
        sum += row[i];

    return (sum % 2 != 0);
}

void roll_back_row_to_end(int** mat, int* rows_lens_arr,
                          size_t start_row_ind, size_t end_row_ind) {

    if (!mat || !end_row_ind) return;
    // change the pointers only, so the array on index start_row_ind, will
    // finally be on index end_row_index, and all others will be moved one
    // position forwards
    for (size_t i = start_row_ind; i < end_row_ind - 1; i++) {
        std::swap(mat[i], mat[i + 1]);
        std::swap(rows_lens_arr[i], rows_lens_arr[i + 1]);
    }
}

void clear_all_odd_sum_rows(int**& mat, size_t& rows_cnt, int*& rows_lens_arr) {

    if (!mat || !rows_lens_arr) return;

    if (rows_cnt == 1 && is_row_with_odd_sum(mat[0], rows_lens_arr[0])) {
        clear_mat(mat, rows_cnt, rows_lens_arr);
        return;
    }

    size_t last_row_ind = rows_cnt - 1;

    // we are going through the rows and move each odd sum row to
    // the end, there we release the memory for it
    for (size_t i = 0; i <= last_row_ind; i++) {
        if (is_row_with_odd_sum(mat[i], rows_lens_arr[i])) {
            roll_back_row_to_end(mat, rows_lens_arr, i, last_row_ind + 1);
            // release the memory for that row
            delete[] mat[last_row_ind];
            --last_row_ind;
        }
    }

    rows_cnt = last_row_ind + 1;
}
// END ----- task 05 -----

// ----- task 06 -----
void sort_saw_matrix_by_rows_size(int** mat, size_t rows_cnt,
                                  int* rows_lens_arr) {
    // the task here is actually quite simple, we just sort
    // the array of sizes, and swap the corresponding pointers
    // for rows on each step
    int min_val;
    int min_ind;
    // classic selection sort
    for (size_t i = 0; i < rows_cnt; i++) {
        min_val = rows_lens_arr[i];
        min_ind = i;
        for (size_t j = i + 1; j < rows_cnt; j++) {
            if (rows_lens_arr[j] < min_val) {
                min_val = rows_lens_arr[j];
                min_ind = j;
            }
        }
        // swap only if there is a smaller element
        if (min_ind != (int)i) {
            std::swap(rows_lens_arr[i], rows_lens_arr[min_ind]);
            // here the sorting of rows happens
            std::swap(mat[i], mat[min_ind]);
        }
    }
}
// END ----- task 06 -----

int main() {

	srand(time(nullptr));

	size_t rows_cnt = 0;
	int*   rows_lens_arr = nullptr;
	int**  mat = nullptr;

    std::cout << "-----------Task 5-----------"   << std::endl;
    std::cout << "Randomly generated saw matrix:" << std::endl;
	create_random_saw_matrix(mat, rows_cnt, rows_lens_arr);
	print_mat(mat, rows_cnt, rows_lens_arr);
	std::cout << "After removing odd sum rows:" << std::endl;
	clear_all_odd_sum_rows(mat, rows_cnt, rows_lens_arr);
	print_mat(mat, rows_cnt, rows_lens_arr);
	clear_mat(mat, rows_cnt, rows_lens_arr);

    std::cout << "-----------Task 6-----------"   << std::endl;
    std::cout << "Randomly generated saw matrix:" << std::endl;
	create_random_saw_matrix(mat, rows_cnt, rows_lens_arr);
	print_mat(mat, rows_cnt, rows_lens_arr);
	std::cout << "After sorting rows by their lengths:" << std::endl;
	sort_saw_matrix_by_rows_size(mat, rows_cnt, rows_lens_arr);
	print_mat(mat, rows_cnt, rows_lens_arr);
	clear_mat(mat, rows_cnt, rows_lens_arr);
	std::cout << std::endl;

	return 0;
}
