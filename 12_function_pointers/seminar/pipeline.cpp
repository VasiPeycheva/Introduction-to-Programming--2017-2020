/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   basic_example.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  Example implementation of pipeline using function pointers.
 */

#include<iostream>
#include<string.h>

// how many manipulators are there
const size_t MANIP_CNT = 5;

// a pointer to function, which takes
// char* as an argument and returns char*
typedef char* (*string_manip_fptr)(char*);

// allocate heap memory for a string with precise size
char* alloc_from_input(char* input) {

	if (input == nullptr)
		return nullptr;

	char* res = new (std::nothrow) char[strlen(input) + 1];

	if (res == nullptr)
		return nullptr;

	strcpy(res, input);

	return res;
}

// free allocated memory for a string
char* free_memory(char* str) {
    // delete on nullptr is safe
    delete[] str;
	return nullptr;
}

// change each digit in a string to a letter
char* map_digit_alpha(char* str) {

	if (str == nullptr)
		return nullptr;

	char* beg = str;

	while (*str != '\0') {
		if (isdigit(*str))
			*str = 'A' + (*str - '0');
		str++;
	}

	return beg;
}

// add 11 to every second char
char* put_some_salt(char* str) {

	if (str == nullptr)
		return nullptr;

	char* beg = str;
	while (*str != '\0') {
		*str += 11;
		str++;
		if (*str == '\0')
			break;
		str++;
	}

	return beg;
}

// just output a string
char* print_result(char* str) {

	if (str == nullptr)
		return nullptr;

	std::cout << str;

	return str;
}


int main() {

    // the idea here is to have a number of serial manipulations,
    // where the input of each manipulation is the output of the previous one
	string_manip_fptr manipulators[MANIP_CNT] = {
		alloc_from_input,
		map_digit_alpha,
		put_some_salt,
		print_result,
		free_memory
	};

    // read the STDIN
	char buff[1024];
	std::cin.get(buff, 1024);

	char* res = buff;
    // go through the manipulators
	for (int i = 0; i < MANIP_CNT; i++) {
		res = manipulators[i](res); // input for each manipulator is the output from the previous one
	}

	return 0;
}
