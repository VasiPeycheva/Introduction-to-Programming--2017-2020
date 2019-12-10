/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   12.2019
  * @brief  Solution for array-algorithms tasks from practice 7.
  */

#include <iostream>
#include <random>
#include <ctime>

const size_t MAX_N       = 1024; // max number of elements we can store in an array
const size_t SORTED_SIZE = 6;    // helper constant for the sixth task

/* matrix size related constants */
const size_t MAX_ROWS = 5;
const size_t MAX_COLS = 5;

/* boys and girls amount for task 8 */
const size_t BOYS_SIZE  = 10;
const size_t GIRLS_SIZE = 10;

// task_01
bool descending_array(int arr[], size_t size) {

    for (size_t i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1])
            return false;
    }

    return true;
}

// task_02
// int because we want return the new size
int insert_elem(int arr[], size_t size, int elem) {

    if (size >= MAX_N)
        return size;

    // if empty
    if (size == 0) {
        arr[0] = elem;
        return 1;
    }

    // we traverse backwards in order to move the elements one step to the right
    // to make room for our new element
    int i;
    for (i = (int)size - 1; (i >= 0 && arr[i] > elem); i--) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = elem;
    return size + 1;
}

// task_03
// because we want to return the updated size
int remove_elem(int arr[], size_t size, int elem) {

    if (size < 1) {
        std::cout << "There are no elements here :(" << std::endl;
        return size;
    }
    size_t i = 0;

    while ((i < size) && (arr[i++] != elem)) {} // to get the position of the element

    if (i >= size) {
        std::cout << "This element does not exist in the given array!" << std::endl;
        return size;
    }

    // to override the value of our element
    while (i < size) {
        arr[i - 1] = arr[i];
        ++i;
    }

    return size - 1;
}

// task_04
bool is_symetric(int arr[], size_t size) {

    size_t middle = size / 2;

	for (size_t i = 0; i < middle; i++)
		if (arr[i] != arr[size - 1 - i])
			return false;

	return false;
}

// helper function to sort the array in task_05
void sort_arr(int arr[], size_t size) {

    int min_val;
    int min_ind;

    for (size_t i = 0; i < size - 1; i++) {
        min_val = arr[i];
        min_ind = i;

        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < min_val) {
                min_val = arr[j];
                min_ind = j;
            }
        }

		std::swap(arr[i], arr[min_ind]);
    }
}

// task_05
int filter_evens(int src_arr[], int dest_arr[], size_t size) {

    int counter = 0;
    for (size_t i = 0; i < size; i++) {
        if (src_arr[i] % 2 == 0)
            dest_arr[counter++] = src_arr[i];
    }

    sort_arr(dest_arr, counter);

    return counter;
}

// task_06
void unite_arrays(int first_arr[], int second_arr[], int result_arr[], size_t size) {

    size_t counter = 0;
    size_t i = 0;
    size_t j = 0;

    while (i < size && j < size) {
        if (first_arr[i] <= second_arr[j])
            result_arr[counter++] = first_arr[i++];
        else
            result_arr[counter++] = second_arr[j++];
    }

    while(i < size)
        result_arr[counter++] = first_arr[i++];

    while (j < size)
        result_arr[counter++] = second_arr[j++];
}

// task_07
void sort_matrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {

	for (size_t i = 0; i < rows; i++) {
        sort_arr(matrix[i], cols);
    }

    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < rows; j++) {
            size_t min_index = j;
            int min_val = matrix[j][i];

            for (size_t k = j + 1; k < rows; k++) {
                if (min_val > matrix[k][i]) {
                    min_val = matrix[k][i];
                    min_index = k;
                }
            }

            if (min_index != j)
                std::swap(matrix[min_index][i], matrix[j][i]);
        }
    }
}

// helper function for task_08
int get_min(int arr[], size_t size) {

    int min_elem = arr[0];
    size_t min_ind = 0;

    for (size_t i = 0; i < size; i++) {
        if(min_elem > arr[i]) {
            min_elem = arr[i];
            min_ind = i;
        }
    }

    std::swap(arr[min_ind], arr[size - 1]);

    return min_elem;
}

void print_array(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

// task_08
void party_array() {

    int boys[BOYS_SIZE] = { 0 };
    int girls[GIRLS_SIZE] = { 0 };
    int result[BOYS_SIZE + GIRLS_SIZE] = { 0 };

    for (size_t i = 0; i < BOYS_SIZE; ) {
		// generating one boy height
        size_t height = rand() % 50 + 150;
		// if it is even we add it to the array by keeping the array sorted
        if (height % 2 == 1) {
            insert_elem(boys, i, height);
            i++;
        }
    }
    for (size_t i = 0; i < GIRLS_SIZE; ) {
        size_t height = rand() % 50 + 150;
		// same as boys but even instead of odd
        if (height % 2 == 0) {
            insert_elem(girls, i, height);
            i++;
        }
    }

	std::cout << "Boys array: " << std::endl;
	print_array(boys, BOYS_SIZE);
	std::cout << "\nGirls array: " << std::endl;
	print_array(girls, GIRLS_SIZE);

    size_t cnt = 0;
    for (size_t i = BOYS_SIZE; i > 0; i--) {

		// get the two smallest people and 'remove' them so
		// that they dont take part in the next minimum
        int smallest_boy = get_min(boys, i);
        int smallest_girl = get_min(girls, i);
        result[cnt++] = smallest_boy;
        result[cnt++] = smallest_girl;
    }

	std::cout << "\nComibned array: " << std::endl;

    print_array(result, BOYS_SIZE + GIRLS_SIZE);
}

void print_matrix(int matrix[][MAX_COLS], size_t rows) {
	for (size_t i = 0; i < rows; i++)
		print_array(matrix[i], MAX_COLS);
}

void init_arr(int arr[], size_t size) {

	for (size_t i = 0; i < size; i++) {
		std::cout << "arr[ " << i << " ] = ";
		std::cin >> arr[i];
	}
}

int main() {

    srand(time(0));

	std::cout << "-----------Task 1-----------" << std::endl;
	int sorted_descending[MAX_N];
	size_t size;
	std::cout << "Enter array size: ";
	std::cin >> size;
	init_arr(sorted_descending, size);

	std::cout << "Is the array sorted in descending order?" << std::endl;
	if (descending_array(sorted_descending, size))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	std::cout << "\n-----------Task 2----------- << std::endl";

	size = 6;
	int sorted_ascending[MAX_N] = { 1, 5, 10, 12, 53, 72 };
	std::cout << "Array before we add 11: " << std::endl;
	print_array(sorted_ascending, size);
	size = insert_elem(sorted_ascending, size, 11);
	std::cout << "Array after we add 11: " << std::endl;
	print_array(sorted_ascending, size);

	std::cout << "\n-----------Task 3-----------" << std::endl;
	std::cout << "Array before we remove 5: " << std::endl;
	print_array(sorted_ascending, size);
	size = remove_elem(sorted_ascending, size, 5);
	std::cout << "Array after we remove 5: " << std::endl;
	print_array(sorted_ascending, size);

	std::cout << "\n-----------Task 4-----------" << std::endl;
	int symietric_arr[MAX_N] = { 1, 5, 7, 5, 1 };
	size = 5;
	std::cout << "Is the array: ";
	print_array(symietric_arr, size);
	std::cout << " symetric?" << std::endl;
	if (is_symetric(symietric_arr, size))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	std::cout << "\n-----------Task 5-----------" << std::endl;
	int src_arr[MAX_N] = { 3, 12, 5, 2, 3, 8, 4 };
	std::cout << "Source array: " << std::endl;
	size = 7;
	print_array(src_arr, size);

	int dest_arr[MAX_N];
	int filtered_size = filter_evens(src_arr, dest_arr, size);
	std::cout << "The filtered array:" << std::endl;
	print_array(dest_arr, filtered_size);

	std::cout << "\n-----------Task 6-----------" << std::endl;
	int first_arr[SORTED_SIZE] = { 10, 12, 15, 20, 31, 81 };
	int second_arr[SORTED_SIZE] = { 1, 7, 18, 20, 26, 102 };
	int third_arr[2* SORTED_SIZE];
	unite_arrays(first_arr, second_arr, third_arr, SORTED_SIZE);
	std::cout << "First array + second array in sorted way: " << std::endl;
	print_array(third_arr, 2 * SORTED_SIZE);

	std::cout << "\n-----------Task 7-----------" << std::endl;
	int matrix[MAX_ROWS][MAX_COLS] = {
		{ 5, 8, 12, 95, 42 },
		{ 3, 9, 7, 1, 6 },
		{ 76, 4, 233, 63, 369},
		{ 93, 943, 73, 1, 2 },
		{ 17, 41, 76, 34, 45 }
	};

	std::cout << "Matrix before it is sorted: " << std::endl;
	print_matrix(matrix, MAX_ROWS);

	std::cout << "Matrix after sorting: " << std::endl;
	sort_matrix(matrix, MAX_ROWS, MAX_COLS);
	print_matrix(matrix, MAX_ROWS);

	std::cout << "\n-----------Task 8-----------" << std::endl;
	party_array();

    return 0;
}
