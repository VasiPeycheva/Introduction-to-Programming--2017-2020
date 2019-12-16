/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   string_basics.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Working C strings - read/write and utility functions.
 */

#include <iostream>
#include <iomanip>
#include <cstring> // std::memset

// forward declaration of our custom implementations
// for strings utility functions
size_t str_len(const char*);
char*  str_cpy(char*, const char*);
int    str_cmp(const char*, const char*);
char*  str_cat(char*, const char*);
// the examples are at -----passing strings as function arguments ------

int main() {

	///---------------------- CREATION -----------------------------

    // we have multiple ways of creating a string:

    // 1. as array of chars with static size (in stack memory)
	const char str[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' };
	//const char here means that we can't change the contain of the string

	// 2. as array of characters  with dynamic size (in heap memory)
	const int size = 6; //the number of symbols
	char* dyn_str = new (std::nothrow) char[size + 1]; // NOTE: ever + 1 for the '\0'

	if (dyn_str) {
		dyn_str[0] = 's'; // writing into the cells
		dyn_str[1] = 't';
		dyn_str[2] = 'r';
		dyn_str[3] = 'i';
		dyn_str[4] = 'n';
		dyn_str[5] = 'g';
		dyn_str[6] = '\0'; //!!!! don't forget about the terminating null
	}
	// free the memory
	delete[] dyn_str;

	// 3. as a pointer to a static allocated literal
	const char* lit_str = "literal String"; // there is a hidden '\0' symbol
										   // at the end of this literal
	// same as
	const char lit_str2[] = "literal String"; // there is a hidden '\0' symbol
	// but...
	char smth[] = "something"; // allocates memory on the stack

	// 4.we can have an array of strings :
	const char* list_of_words[] = { "firstWord", "second String" , "and etc" };


    ///---------------------- WRITING TO OUTPUT -----------------------------

	// we can print each symbol of the string
	int i = 0;
	while (lit_str[i] != '\0')     // until the terminating null
		std::cout << lit_str[i++]; // outputs lit_str[i] and then i = i + 1
	std::cout << std::endl;

	// or we can just output the whole string using
	std::cout << lit_str; // it will do the same thing the upper lines do
	std::cout << std::endl;

	// to output the words form our list
	for (size_t j = 0; j < sizeof(list_of_words)/sizeof(char*); j++)
        std::cout << "list_of_words[" << j << "] "
                  << list_of_words[j] << std::endl;
    std::cout << std::endl;

    ///---------------------- READING FROM INPUT -----------------------------

	// the normal reading:
	// char buff[64];
	// cin >> buff;
	// can be dangerous, because
	// we don't know how many symbols will be entered form the standard input
	// before ' ' or \n, so we don't know if our allocated memory is enough
	// to store the whole input
	/*
	for example:
	char wrong_str[3];      // allocating memory for 12 chars
	std::cin >> wrong_str; // someone enters "abcd"
	which writes after our buffer and our program will die :(
	*/
    // reading a word (properly)
    const int max_size = 256;
    char word[max_size];
    std::cout << "Enter a word: ";
    std::cin >> std::setw(256) >> word; // reads max 255 symbols and adds '\0'
    std::cout << "The word is: " << word << std::endl;
    // clean the left '\n'
    char c = std::cin.get();
	if (c != '\n') std::cin.putback(c);
    //
	// reading a line of text:
	char buff[max_size];
	// will read a whole line to \n or maximum max_size - 1 chars
	// automatically adds '\0' to our string
	std::cout << "Input a line text: ";
	std::cin.getline(buff, max_size);
	std::cout << "The text is: " << buff << std::endl;

	// if we want to reuse this buffer
	// we can clean it:
	memset(buff, 0, max_size); // this will write 0's in each cell of our buffer

	// now we can read with getline up to a given character

	char delimiter = ' ';

	std::cout << "Enter some text (words with spaces): " << std::endl;
	std::cin.getline(buff, max_size, delimiter); // will take the first word form the input
	std::cout << "The first word is: " << buff << std::endl;

    ///---------------------- PASSING AS FUNCTION ARGUMENTS -----------------------------

	std::cout << std::endl
              << "Basic functions examples:"
              << std::endl;

	const char* dog_first_name  = "Goofy";
	const char* dog_second_name = "Goof";

	const size_t full_name_size = 32;
	char full_name[full_name_size];       // allocated enough memory for both strings
	memset(full_name, 0, full_name_size); // zero the memory

	std::cout << "The first name \""  << dog_first_name
              << "\" has length of: " << str_len(dog_first_name) << std::endl;

	std::cout << "The full name is empty: " << full_name << std::endl;

	std::cout << "The full name after coping the first name: "
              << str_cpy(full_name, dog_first_name) << std::endl;

	std::cout << "The full name after concatenating the second name: "
              << str_cat(full_name, dog_second_name) << std::endl;

	std::cout << "Comparing the two names:" << std::endl;

	int res = str_cmp(dog_first_name, dog_second_name);

	if (res > 0)
		std::cout << "The first name is lexicographical first." << std::endl;
	if (res == 0)
		std::cout << "The two names are lexicographical equal." << std::endl;
	if (res < 0)
		std::cout << "The second name is lexicographical first." << std::endl;

	return 0;
}

// Get the length of a string
/// @see http://www.cplusplus.com/reference/cstring/strlen/
size_t str_len(const char* str) {

	size_t len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

// Copy a string from source to the destination
/// @see http://www.cplusplus.com/reference/cstring/strcpy/
char* str_cpy(char* dest, const char* src) {

	size_t i = 0;
	while (src[i]) { // same as src[i] != '\0'
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}

// Compares two strings lexicographically
// returns:
// < 0 if the rhs is the bigger one
// 0 if both are equal
// > 0 if the lhs is the bigger one
/// @see http://www.cplusplus.com/reference/cstring/strcmp/
int str_cmp(const char* lhs, const char *rhs) {

	size_t i;

	for (i = 0; lhs[i] != '\0' && lhs[i] == rhs[i]; i++)
		;

	return (int)(lhs[i] - rhs[i]);
}

// Concatenate a string to another
// as known as strings append
/// @see http://www.cplusplus.com/reference/cstring/strcat/
char* str_cat(char* dest, const char* src) {

	size_t dest_i = strlen(dest);
	size_t i = 0;

	while (src[i] != '\0')
		dest[dest_i++] = src[i++]; // dest[dest_i] = src[i], then dest_i++, i++

	dest[dest_i] = '\0';

	return dest;
}
