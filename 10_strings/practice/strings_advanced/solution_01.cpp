/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_01.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   01.2020
  * @brief  Solution for task 1 from advanced_string tasks (practice 11).
  */

#include <iostream> // cin, cout
#include <cstring>  // strlen, strcat

const unsigned int WORD_CNT = 3;
const unsigned int MAX_INPUT = 1024;

bool check_dic(const char* dic[], const char* word) {
	for (size_t i = 0; i < WORD_CNT; i++)
		if (std::strcmp(word, dic[i]) == 0) // if the word on position i
			return true;				    // in the dictionary is as same as the given one

	return false;
}

int main() {

	const char* dic[] = { "cats", "dogs", "animals" };

	char input[MAX_INPUT];	// "it is raining cats and dogs";

	std::cin.getline(input, MAX_INPUT); //reading the whole input

	// for each word form it, check into the dictionary

	// takes the first word
	char* curr_word = std::strtok(input, " ");
	unsigned int how_many = 0;
	while (curr_word != nullptr) {
		if (check_dic(dic, curr_word))
			how_many++;
		// takes the next word form input string
		curr_word = std::strtok(nullptr, " ");
	}

	std::cout << how_many << std::endl;

	return 0;
}
