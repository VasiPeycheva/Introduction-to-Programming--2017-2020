/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for function tasks from practice 6.
  */

#include <iostream>

const size_t MAX_N = 1024; // max number of elements we can store

// task_02
void fill_array(int arr[], size_t size) {

	// iterating through array's elements
	for (size_t i = 0; i < size; i++) {
		// reading each element's value
		std::cout << "Enter value for element on index " << i << ": ";
		std::cin >> arr[i];
	}
}

void print_array(int arr[], size_t size) {

	for (size_t i = 0; i < size; i++) {
		// printing each element's value
		std::cout << "array [" << i << "]= "
			      << arr[i] << std::endl;
	}
	std::cout << std::endl;
}
// ------------------------

// task_03
long long int sum_elements(int arr[], size_t size) {

	long long int sum = 0;

	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

long long int product_elements(int arr[], size_t size) {

	long long int prod = 1;

	for (size_t i = 0; i < size; i++) {
		prod *= arr[i];
	}

	return prod;
}
// ------------------------

// task_04
size_t min_array(int arr[], size_t size) {

	size_t min_index = 0; // the index of the minimal elem
						  // in the beginning we assume that the first elem
						  // is the smallest one
	for (size_t i = 1; i < size; i++) {
		// checks if we should update the min elem's index
		if (arr[min_index] > arr[i]) {
			min_index = i;
		}
	}

	return min_index;
}

size_t max_array(int arr[], size_t size) {

	size_t max_index = 0; // the index of the maximal elem
						  // in the beginning we assume that the first elem
						  // is the largest one

	for (size_t i = 1; i < size; i++) {
		// checks if we should update the max elem's index
		if (arr[max_index] < arr[i]) {
			max_index = i;
		}
	}

	return max_index;
}
// ------------------------


// task_05
// helper function for task 5 that checks if a given number is a prime or not
bool is_prime(int n) {

	n = (n > 0) ? n : -n; // abs(n)

	for (int i = 2; i * i < n; i++) {  // we don't have to use sqrt
		if (n % i == 0) {			 // we can if check  i * i is less than n
			return false;
		}
	}
	return true;
}

// prints all prime elements
void print_primes_array(int arr[], size_t size) {

	for (size_t i = 0; i < size; i++) {
		// checks if we should print the current number
		if (is_prime(arr[i])) {
			std::cout << arr[i] << ' ';
		}
	}
}
// ------------------------

// task_06
long long int product_index_odd_elems(int arr[], size_t size) {

	long long int prod = 1;

	for (size_t i = 0; i < size; i++) {
		if (arr[i] % 2 == 1) {	// checks if the number is odd
			prod *= i;		    // multiplies the product by the current index -> i
		}
	}
	return prod;
}
// ------------------------


// task_07
long long int diff_elems(int arr[], size_t size) {

	long long int prod_even = 1;
	long long int sum_odd = 0;

	for (size_t i = 0; i < size; i++) {
		if (i % 2 == 0) {
			prod_even *= arr[i];
		} else {
			sum_odd += arr[i];
		}
	}

	return prod_even - sum_odd;
}
// ------------------------

// task_08
// helper function for task 8 that checks if a number has more up bits (1) or more down bits (0)
// in its binary representation without checking the sign bit (which is the MSB)
bool has_more_up_bits(int n) {

	unsigned short ones = 0;

	for (int i = 0; i < sizeof(int) * 8 - 2; i++) {
		if (n & (1 << i)) {
			ones++;
		}
	}
	// ones > 15
	return ones > (sizeof(int) * 8 - 1) / 2;
}

long long int sum_up_bits_elems(int arr[], size_t size) {

	long long int sum = 0;

	for (size_t i = 0; i < size; i++) {
		if (has_more_up_bits(arr[i])) {
			sum += arr[i];
		}
	}

	return sum;
}
// ------------------------


int main() {

	int arr[MAX_N]; // allocating the memory for the array
	size_t size;    // logical size, we will use
				    // only a part of our allocated memory
				    // !!! size_t is a typedef for unsigned int !!!

	std::cout << "-----------Task 2-----------" << std::endl;
	do {
		std::cout << "Enter a number for array size less than 1024:" << std::endl;
		std::cin  >> size;
	} while (size >= MAX_N);

	fill_array(arr, size);

	std::cout << "\nThe array content is: " << std::endl;
	print_array(arr, size);

	std::cout << "-----------Task 3-----------" << std::endl;
	std::cout << "Sum of all elements: "
	          << sum_elements(arr, size) << std::endl;

	std::cout << "Product of all elements: "
	          << product_elements(arr, size) << std::endl;

	std::cout << "-----------Task 4-----------" << std::endl;
	size_t min_index = min_array(arr, size);
	std::cout << "The smallest element is on index "
		      << min_index << " and it's value is: " << arr[min_index] << std::endl;

	size_t max_index = max_array(arr, size);
	std::cout << "The largest element is on index "
		      << max_index << " and it's value is: " << arr[max_index] << std::endl;

	std::cout << "-----------Task 5-----------" << std::endl;
	std::cout << "All prime elements are:" << std::endl;
	print_primes_array(arr, size);
	std::cout << std::endl;

	std::cout << "-----------Task 6-----------" << std::endl;
	std::cout << "Product of indexes of all odd elements: "
              << product_index_odd_elems(arr, size) << std::endl;

	std::cout << "-----------Task 7-----------" << std::endl;
	std::cout << "Difference between(P) product of elements on even indexes\n"
                 "and (S) sum of elements on odd indexes / P - S = "
              << diff_elems(arr, size) << std::endl;

	std::cout << "-----------Task 8-----------" << std::endl;
	std::cout << "The sum of all elements with more ones\n"
                 "in their binary representation is: "
		      << sum_elements(arr, size);

	return 0;
}
