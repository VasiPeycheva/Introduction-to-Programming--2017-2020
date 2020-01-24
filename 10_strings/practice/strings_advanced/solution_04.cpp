/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_04.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for task 4 from advanced_string tasks (practice 11).
  */

#include <iostream>
#include <cstring>

// gets the number of same symbols from the beginning of str
// ex: 111321 -> 3 (we have there ones)
size_t get_same_symb_cnt(const char* str) {

	size_t cnt = 1;
	while (*str != '\0' && *str == *(str + 1)) {
		++str;
		++cnt;
	}

	return cnt;
}

// add number and symbol to a string
// 112 -> append 3, 2 times -> 11223
bool append_chars(char*& str, size_t cnt, char c) {

    if (str == nullptr) {
        str = new (std::nothrow) char[3]; // cnt, char, '\0'
        if (!str) return false;
        str[0] = '0' + cnt;
        str[1] = c;
        str[2] = '\0';
        return true;
    }

    // allocate enough memory
    size_t old_len = strlen(str);
    size_t new_len = old_len + cnt + 1;
    char* new_mem = new (std::nothrow) char[new_len + 1];
    if (!new_mem) return false;
    // copy the old contain
    std::strcpy(new_mem, str);
    // append the new characters
    char addends[] = { (char)('0' + cnt), c, '\0' };
    std::strcat(new_mem, addends);
    // release the old memory
    delete[] str;
    // redirect str to the new memory
    str = new_mem;
    return true;
}

// by a sequence 11213, allocate new string having 21121113 (the step of look and say)
char* look_and_say_step(const char* old_sequence) {

    char* res = nullptr;

    while (*old_sequence) {
        size_t cnt = get_same_symb_cnt(old_sequence);
        if (!append_chars(res, cnt, *old_sequence)) {
            delete[] res;
            return nullptr;
        }
        old_sequence += cnt;
    }

    return res;
}

char* get_nth_look_and_say(size_t n) {

	char* init_member = new (std::nothrow) char[2];
	init_member[0] = '1';
	init_member[1] = '\0';

    char* old_member = init_member;
    char* new_member = nullptr;
    while (n--) {
        // on each step -> create new string using the old one
        new_member = look_and_say_step(old_member);
        // release the memory for the old one
        delete[] old_member;
        // error check
        if (!new_member) return nullptr;
        // save the new member
        old_member = new_member;
    }

    return old_member;
}

int main() {

    char* seq = get_nth_look_and_say(6);
    if (!seq) return 1;
    std::cout << "Sixth member: " << seq << std::endl;

    char* next = look_and_say_step(seq);
    if (!next) return 1;
    std::cout << "Seventh member: " << next << std::endl;

    delete[] seq;
    delete[] next;

	return 0;
}
