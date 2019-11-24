/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   matrices.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Example for working with 2D arrays (Matrices).
 */


#include <iostream>
#include <iomanip>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>   // std::time()
#include <math.h>  // std::log10()

const size_t MAX_ROW = 10; // max number of rows
const size_t MAX_COL = 10; // max number of columns (how many elements each row will have)
const int    MAX_EL  = 11; // maximum value for the random fill


// print a matrix
// notice: the matrix is passed to the function with number of columns specialized!
// we pass a "large enough" matrix, than the parameters rows and cols describe the
// real logical size of the matrix
void print_mat(int mat[][MAX_COL], size_t rows, size_t cols) {

    int cells = (int)std::log10(MAX_EL) + 1;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(cells) << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// fill the matrix with random numbers
void init_mat(int mat[][MAX_COL], size_t rows, size_t cols) {

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mat[i][j] = std::rand() % MAX_EL;
}

// find the sum of the main diagonal of a given matrix
// notice: the matrix could be square or not
int sum_main_diagonal(int mat[][MAX_COL], size_t rows, size_t cols) {

    int sum = 0;

    /* slower and sillier way:
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (i == j)
                sum += mat[i][j];
    */

    // better way: all element on the main diagonal have same x, y coordinates
    for (size_t i = 0; i < rows; i++)
            sum += mat[i][i];

    return sum;
}

// find the sum of elements from a given matrix row
// notice: the row is actually a 1D array
int sum_row(int arr[], size_t size) {

    int sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

// find the multiplication of sums for each row
int mul_sum_row(int mat[][MAX_COL], size_t rows, size_t cols) {

    int pr = 1;
    for (size_t row = 0; row < rows; row++) // for each row
        pr *= sum_row(mat[row], cols);   // pass the row to the function and get the sum

    return pr;
}

int main() {

    // fixed and initialized matrix:
    const int L_SIZE = 3; // logical size
    int fixed_mat[][MAX_COL] = {
        { 1, 2, 3 }, // fixed_mat[0] (a.k.a first row)
        { 4, 5, 6 }, // second row
        { 7, 8, 9 }, // third row
    };

    std::cout << "Fixed matrix:" << std::endl;
    print_mat(fixed_mat, L_SIZE, L_SIZE);


    // initialize a random matrix:
    size_t rows, cols;
    std::cout << "Enter number of rows [0, " << MAX_ROW << "]:" << std::endl;
    std::cin >> rows;
    std::cout << "Enter number of columns [0, " << MAX_COL << "]:" << std::endl;
    std::cin >> cols;

    if (rows >= MAX_ROW || cols >= MAX_COL) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    // create "large enough" matrix
    int mat[MAX_ROW][MAX_COL];
    // initialize the random generator
    std::srand(std::time(0));
    // fill the matrix
    init_mat(mat, rows, cols);
    // output it
    std::cout << "The randomly generated matrix looks like:" << std::endl;
    print_mat(mat, rows, cols);

    std::cout << "Sum of elements on the main diagonal: " << sum_main_diagonal(mat, rows, cols) << std::endl;
    std::cout << "Product of rows sums: " << mul_sum_row(mat, rows, cols) << std::endl;

    return 0;
}
