/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_02.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for recursion task 02 from practice 13.
  */


#include <iostream>
#include <cstring>

const unsigned int DIGITS_COUNT = 10;
// --- WITH ARRAY -------
bool has_same_digits_arr_rec(unsigned int num, bool digits_seen[DIGITS_COUNT]) {

	// only one digit left
	if (num < 10)
		return digits_seen[num];

	// more than one digit in the number
	// check the last one
	if (digits_seen[num % 10]) // if seen
		return true;

	// if not seen
	digits_seen[num % 10] = true;

	return has_same_digits_arr_rec(num / 10, digits_seen);
}

bool has_same_digits_arr(unsigned int num, bool digits_seen[DIGITS_COUNT]) {

	// ensure that all cell are marked as no such digit
	std::memset(digits_seen, false, DIGITS_COUNT * sizeof(bool));

	return has_same_digits_arr_rec(num, digits_seen);
}

// --- WITHOUT ARRAY -------

bool has_same_digits_rec(unsigned int num, unsigned short cur_digit) {

	if (num < 10) // only one digit
		return num == cur_digit;

	if (num % 10 == cur_digit) // check the last one
		return true;

	if (has_same_digits_rec(num / 10, cur_digit)) // same digit in the rest of the number
		return true;
	else
		return has_same_digits_rec(num / 10, num % 10); // try with the next digit
}

bool has_same_digits(unsigned int num) {

	if (num < 10)
		return false;

	return has_same_digits_rec(num / 10, num % 10);
}

int main() {

	unsigned int num = 125453;

	std::cout << "Has same digits " << num << '?' << std::endl;

    // false there is not such digit
    // true there is
    bool digits_seen[DIGITS_COUNT] = { false, };

    std::cout << "Answer with array: ";
	if (has_same_digits_arr(num, digits_seen))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

    std::cout << "Answer without array: ";
	if (has_same_digits(num))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	return 0;
}
