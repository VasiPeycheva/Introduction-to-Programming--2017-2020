#include<iostream>
#include<string.h>

//how many manipulators are there
const size_t MANIP_SIZE = 5;

//a pointer to function, which takes
//char* as an argument and returns char*
typedef char* (*fptrStringManip)(char*);

char* allocFromInput(char* input) {

	if (input == nullptr)
		return nullptr;

	char* res = new (std::nothrow) char[strlen(input) + 1];

	if (res == nullptr)
		return nullptr;

	strcpy(res, input);

	return res;
}

char* freeMemory(char* str) {

	if(str != nullptr)
		delete []str;

	return nullptr;

}

char* mapDigitAlpha(char* str) {

	if (str == nullptr)
		return nullptr;

	char* beg = str;

	while (*str != '\0') {

		if(isdigit(*str))
			*str = 'A' + (*str - '0');

		str++;
	}

	return beg;
}

//adds 11 to every second char
char* putSomeSalt(char* str) {

	if (str == nullptr)
		return nullptr;

	char* beg = str;
	while (*str != '\0') {

		*str += 11 ;

		str++;

		if (*str == '\0')
			break;

		str++;
	}

	return beg;
}

char* printResult(char* str) {

	if (str == nullptr)
		return nullptr;

	std::cout << str;

	return str;
}


int main() {

	fptrStringManip manipulators[MANIP_SIZE] = {

		allocFromInput,
		mapDigitAlpha,
		putSomeSalt,
		printResult,
		freeMemory

	};

	char buff[1024];

	std::cin.get(buff, 1024);

	char* res = buff;

	for (int i = 0; i < MANIP_SIZE; i++)
		res = manipulators[i](res);

	return 0;
}