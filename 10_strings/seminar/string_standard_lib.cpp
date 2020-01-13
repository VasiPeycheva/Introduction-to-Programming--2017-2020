/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   string_standard_lib.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Working C strings - using the C standard library.
 */

#include <iostream>
#include <iomanip>
#include <cstring> // std::str*()
#include <cstdlib> // std::atoi

const int BUFFER_SIZE = 512;
const int SMALL_BUF_SIZE = BUFFER_SIZE / 64;

int main() {

    char buff[BUFFER_SIZE];
    std::cout << "Enter a line string:" << std::endl;
    std::cin.getline(buff, BUFFER_SIZE);

    char small_buff[SMALL_BUF_SIZE];
    ///  ----------- strcpy ---------------
    // partial copy, for full copy use strcpy
    std::strncpy(small_buff, buff, SMALL_BUF_SIZE - 1);
    // this copy DOES NOT add '\0'
    small_buff[SMALL_BUF_SIZE - 1] = '\0';

    std::cout << "After coping only the first "
              << SMALL_BUF_SIZE - 1 << " characters:"
              << std::endl
              << small_buff
              << std::endl << std::endl;

    ///  ----------- strcat ---------------
    char greetings_str[BUFFER_SIZE] = "Happy";
    std::cout << "Greetings before concatenation: "
              << greetings_str << std::endl;
    // concatenation == append
    std::strcat(greetings_str, " New Year!");
    std::cout << "Greetings after concatenation: "
              << greetings_str << std::endl;

    ///  ----------- strcmp ---------------
    const char* other_greetings_str = "Merry Christmas!";
    std::cout << std::quoted(greetings_str)
              << " is equal to "
              << std::quoted(other_greetings_str)
              << "? - ";
    if (std::strcmp(greetings_str, other_greetings_str) == 0) // notice: == 0 only means equal
        std::cout << "Yes!";
    else
        std::cout << "No!";

    std::cout << std::endl;

    const char* greetings_prefix = "Happy";
    std::cout << std::quoted(greetings_str)
              << " starts with "
              << std::quoted(greetings_prefix)
              << "? - ";
    if (std::strncmp(greetings_str, greetings_prefix, std::strlen(greetings_prefix)) == 0)
        std::cout << "Yes!";
    else
        std::cout << "No!";

    std::cout << std::endl << std::endl;

    ///  ----------- strchr / strrchr ---------------
    std::cout << "First occurrence of \'N\' in "
              << std::quoted(greetings_str)
              << " - " << std::endl;
    const char* res = std::strchr(greetings_str, 'N');
    if (res == nullptr) {
        std::cout << "Not found!";
    } else {
        int pos = res - greetings_str + 1; // find the position using pointer arithmetic
        std::cout << "Found at: " << pos
                  << ". The rest of the string: "
                  << res;
    }
    // strrchr can be used in the same manner, but finds the last occurrence

    std::cout << std::endl << std::endl;

    ///  ----------- strstr ---------------
    const char* first_searched_str = "New";
    std::cout << "Searching for "
              << std::quoted(first_searched_str)
              << " in "
              << std::quoted(greetings_str)
              << " - ";
    res = std::strstr(greetings_str, first_searched_str);
    if (res == nullptr) {
        std::cout << "Not found!";
    } else {
        int pos = res - greetings_str + 1;
        std::cout << "Found at: " << pos
                  << ". Result: "
                  << res
                  << std::endl;
        // let's hack the string :)
        strncpy((char*)res, "Old", 3);
        std::cout << "The greeting after hacking: "
                  << std::quoted(greetings_str);
    }

    std::cout << std::endl << std::endl;

    ///  ----------- strstr / atoi ---------------
    char example_str[] = "2017, 2018, 2019, 2020";
    std::cout << "Let's have this example string: "
              << std::quoted(example_str)
              << std::endl;

    std::cout << "Separating it to tokens using [\',\', \' \'] as delimiters:" << std::endl;
    char* token = std::strtok(example_str, ", ");
    int i = 0;
    int sum = 0;
    while (token != nullptr) { // still have tokens
        std::cout << "Token (" << i++ << ") :"
                  << std::quoted(token)
                  << std::endl;
        sum += std::atoi(token); // convert the token to integer and add it to the sum
        token = std::strtok(nullptr, ", "); // get the next token
    }

    std::cout << "Sum of all years: " << sum << std::endl;

	return 0;
}

