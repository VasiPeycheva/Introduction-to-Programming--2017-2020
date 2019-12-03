/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   12.2019
  * @brief  Solution for function tasks from practice 7.
  */

#include <iostream>
#include <random>
#include <time.h>

const size_t MAX_N = 1024; // max number of elements we can store
const size_t MAX_ROWS = 10;
const size_t MAX_COLS = 10;
const size_t BOYS_SIZE = 10;
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
    size_t i;
    for (i = size - 1; (i >= 0 && arr[i] > elem); i--) {
        arr[i + 1] = arr[i]; 
    }
  
    arr[i + 1] = elem;
    return size + 1;
}

// task_03
// because we want to return the updated size
int delete_elem(int arr[], size_t size, int elem) {

    if (size < 1) {
        std::cout << "There are no elements here :( \n";
        return size;
    }
    size_t i = 0;
    
    while ((i < size) && (arr[i++] != elem)) {} // to get the position of the element
    
    if (i >= size) {
        std::cout << "This element does not exist in the given array!\n";
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
    size_t i = 0;

    while ((i < middle) && (arr[i] == arr[size - 1 - i])) {
        ++i;
    }
    
    if (i >= middle) 
        return true;

    else 
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
        
        if (min_ind != (int)i) {
            int t  = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = t;
        }
    }
}

// task_05
int filter_primes(int src_arr[], int dest_arr[], size_t size) {

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
int get_min(int arr[], size_t& size) {

    int min_elem = arr[0];
    size_t min_ind = 0;

    for (size_t i = 0; i < size; i++) {
        if(min_elem > arr[i]) { 
            min_elem = arr[i];
            min_ind = i;
        }
    }
    
    if (min_ind != 0)
        std::swap(arr[min_ind], arr[size--]);

    return min_elem;
}

void print_array(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// task_08
void party_array() {

    int boys[BOYS_SIZE] = { 0 };
    int girls[GIRLS_SIZE] = { 0 };
    int result[BOYS_SIZE + GIRLS_SIZE] = { 0 };

    for (size_t i = 0; i < BOYS_SIZE; ) {
        size_t height = rand() % 50 + 150;
        if (height % 2 == 1) {
            insert_elem(boys, i, height);
            i++;
        }
    }
    for (size_t i = 0; i < GIRLS_SIZE; i++) {
        size_t height = rand() % 50 + 150;
        if (height % 2 == 0) {
            insert_elem(boys, i, height);
            i++;
        }
    }

    size_t cnt = 0;
    for (size_t i = BOYS_SIZE; i > 0; i--) {

        int smallest_boy = get_min(boys, i);
        int smallest_girl = get_min(girls, i);
        result[cnt++] = smallest_boy;
        result[cnt++] = smallest_girl;
    }
    
    print_array(result, BOYS_SIZE + GIRLS_SIZE);
}

int main() {

    srand(time(0));

    int arr1[6] = {1, 2, 4, 6, 7, 10};
    int arr2[6] = {3, 5, 8, 9, 11, 12 };
    int arr3[12] = { 0 };

    unite_arrays(arr1, arr2, arr3, 6);

    std::cout << "The array is in descending order: " << is_symetric(arr1, 6);

    return 0;
}