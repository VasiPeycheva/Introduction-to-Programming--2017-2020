#include<iostream>
#include<string.h> //strtok, strlen, strcpy
#include<time.h> //time
#include<stdlib.h> //rand

const unsigned int MAX_INPUT = 1024;

//how many spaces are out there + 1
size_t howManyWords(const char* str) {

	if (str == nullptr)
		return 0;

	size_t cnt = 1, i = 0; //at least one word

	while (str[i] != '\0') {

		if (str[i] == ' ')
			cnt++;

		i++;
	}

	return cnt;

}

void freeWords(char**& words, size_t size) {

	for (size_t i = 0; i < size; i++)
		delete[] words[i];

	delete words;

	words = nullptr;

}

void yodaTalks(char** words, size_t size) {

	//here we will check the taken words
	bool* isTakenWord = new (std::nothrow) bool[size];

	if (isTakenWord == nullptr)
		return;

	//mark all as untaken
	for (size_t i = 0; i < size; i++)
		isTakenWord[i] = false;

	size_t numTaken = 0;
	size_t index;

	//while there is untaken word
	while (numTaken < size) {

		index = rand() % size; //trying to take this word

		while (isTakenWord[index])
			index = (index + 1) % size; //try the next one, if outsize array, start from the beg

		//mark it as taken
		isTakenWord[index] = true;
		numTaken++;

		//print it
		std::cout << words[index];

		if(numTaken != size) //no space after the last word
			std::cout << ' ';

	}

	delete[] isTakenWord;
}


int main() {

	char buff[MAX_INPUT];

	std::cin.getline(buff, MAX_INPUT);

	size_t wordsCnt = howManyWords(buff);

	//allocating pointer for each string ( word )
	char** words = new char*[wordsCnt];

	//taking the first word from the buff
	char* word = strtok(buff, " ");

	int i = 0;
	while (word != nullptr) {

		//allocating memory for the current word
		words[i] = new (std::nothrow) char[strlen(word) + 1];

		if (words[i] == nullptr) {

			std::cerr << "can't allocate memory :( !\n";

			freeWords(words, i - 1);

			return -1;
		}

		//copying its contain
		strcpy(words[i], word);

		i++;

		//taking the next word
		word = strtok(nullptr, " ");
	}

	//makes us sure that all the memory is successfully allocated and copied
	//for (int j = 0; j < i; j++)
		//std::cout << words[j] << std::endl;

	srand(time(nullptr));

	yodaTalks(words, wordsCnt);

	freeWords(words, wordsCnt);

	return 0;
}