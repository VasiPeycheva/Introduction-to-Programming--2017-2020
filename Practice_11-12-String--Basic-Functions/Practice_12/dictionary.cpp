#include<iostream> //cin, cout

#include<string.h> // strlen , strcat ///

const unsigned int WORD_CNT = 3;
const unsigned int MAX_INPUT = 1024;

bool checkDic(const char* dic[], const char* word) {

	for (size_t i = 0; i < WORD_CNT; i++)
		if (strcmp(word, dic[i]) == 0) //if the word on position i 
			return true;						//in the dicionary is as same as the given one

	return false;

}



int main() {

	const char* dic[] = { "cats", "dogs", "animals" };

	char input[MAX_INPUT];// = "it is raining cats and dogs";

	std::cin.getline(input, MAX_INPUT); //reading the whole input

	//for each word form it, check into the dictionary

	//takes the first word
	char* currWord = strtok(input, " ");

	unsigned int howMany = 0;

	while (currWord != nullptr) {

		if (checkDic(dic, currWord))
			howMany++;

		// takes the next word form input string
		currWord = strtok(nullptr, " "); 
	}

	std::cout << howMany << '\n';

	return 0;
}