/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_05.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for task 5 from advanced_string tasks (practice 11).
  */

#include <iostream>
#include <cstring>

bool check_pattern(const char* str, const char* pattern) {

    if (!str || !pattern) return false;

    while (*pattern) {
        char cur_sym = *pattern;
        if (cur_sym == '?') {
            // if we got at least one symbol in the string, just consume it
            if (!(*str)) return false;
            ++pattern;
            ++str;
        } else if (cur_sym == '*') {
            char next_sym = *(pattern + 1);
            if (next_sym == '\0') // the pattern has come the it's end
                return true;
            if (next_sym == '?' || next_sym == '*') { // *? => ? and ** => *
                ++pattern;
            } else {
                // we should find the next occurrence of `next_sym` in str
                str = std::strchr(str, next_sym);
                if (!str) return false;
                pattern += 2;
                ++str;
            }
        } else {
            // just an ordinary symbol
            if (cur_sym != *str)
                return false;
            ++pattern;
            ++str;
        }
    }

    return *str == '\0';
}

int main() {

    const char* pattern = "te?t.*";
    std::cout << "Checking with pattern: " << pattern << std::endl;

    const char* test_strings[] = { "test.txt", "text.pdf", "tekt.sad", "teqt.qwerty", "baba" };
    size_t cnt = sizeof(test_strings) / sizeof(char*);

    for (size_t i = 0; i < cnt; i++) {
    std::cout << test_strings[i] << ": "
              << std::boolalpha
              << check_pattern(test_strings[i], pattern)
              << std::endl;
    }

    std::cout << "testing \"test.txt\" with pattern \"*.?x?*\": "
              << std::boolalpha
              << check_pattern("test.txt", "*.?x?*")
              << std::endl;

	return 0;
}
