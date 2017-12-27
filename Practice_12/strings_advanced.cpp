#include<iostream> //cin, cout

#include<string.h> // strlen , strcat ///

//#include<ctype.h> isalpha, isdigit, islower etc could be found,
//it is a part of string.h


//task1 - > a standard function from ctype.h 
//more at : http://www.cplusplus.com/reference/cctype/isalpha/
bool isAlpha(char c) {

	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

//task2 -> also a standard function
bool isDigit(char c) {

	return c >= '0' && c <= '9';
}


//task3 
void toLower(char* str) {

	//protects our function
	//from invalid usage
	if (str == nullptr)
		return;

	//the standard way of iterating a string
	size_t i = 0;

	//loop until the terminating symbol
	while (str[i] != '\0') {

		if (islower(str[i])) // using islower from ctype.h
			str[i] -= 'a' - 'A'; //using the fact that the lower letters are before
								//the upper ones, so changing is  just 
								//'moving around into the ASCII table'
		i++;
	}
}

//task4
//pretty simple, nothing tricky at all
void changeSpSymbol(char* str, char toChange, char changeWith) {

	if (str == nullptr)
		return;

	size_t i = 0;

	while (str[i] != '\0') {
		
		if (str[i] == toChange)
			str[i] = changeWith;

		i++;
	}
}

//task5 !!! atoi already included by string.h !!! 
int m_atoi(const char* str) { //we will not change the string's
								//contain so passing it by const 
								//is the right way to go

	//will not compile in debug mode when nullptr or NULL passed,
	//but just to insure everything 

	if (str == nullptr)
		return 0; // maybe

	int result = 0;

	int sign = 1;

	if (*str == '-') { // the first char is -

		sign = -1;
		str++; //moves the pointer one position forward
	}

	size_t i = 0;

	while (str[i] != '\0') {

		result *= 10; // a new space at the end of the number
		result += str[i] - '0'; //putting the new digit at the end

		i++;
	}

	return result * sign;

}


//task6
bool isPalindrome(const char* str) {

	if (str == nullptr)
		return false;

	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2) //looking at the front and at the end
		if (str[i] != str[len - (i + 1)]) // the last element is on index str[len-1]
			return false;
		else
			i++;

	//if the first half is the reversed second
	return true;

}

//task7
void reverse(char* str) {

	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2) { //looking at the front and at the end
		std::swap(str[i], str[len - (i + 1)]);
		i++;
	}

}


//task8
//returns false if there was some kind of memory problem
bool dynamicConcat(char*& dest, const char* src) { //the dest pointer will be redirected, 
												//so taking it by ref is essential

	char* newMemBuff = new (std::nothrow) char[strlen(dest) + strlen(src) + 1]; 
	// enough memory for both strings' contain + '\0'

	if (newMemBuff == nullptr)
		return false;

	strcpy(newMemBuff, dest); //copy the first part
	strcat(newMemBuff, src); //appends the second part

	//clear the unneeded memory
	delete[] dest;

	dest = newMemBuff; //redirecting the pointer from main/other function

	return true;

}					


//task9

bool isVowel(char c) {

	if (!isAlpha(c))
		return false;

	c = tolower(c);

	return c == 'a' || c == 'e' || 
		   c == 'i' || c == 'u' || 
		   c == 'o';
	
}
void compact(char*& str) {//will redirect str -> reference!

	if (str == nullptr)
		return;

	char* buff = new (std::nothrow) char[strlen(str) + 1]; //alloc a buff

	if (buff == nullptr)
		return;

	size_t i = 0, i_buff = 0;

	while (str[i] != '\0') {

		if (isVowel(str[i])) { //skipping the vowels
			i++;
			continue;
		}

		//copying other symbols
		buff[i_buff++] = str[i++];
	}

	buff[i_buff] = '\0';

	delete[] str; //we don't need this mem anymore

	//new memory as we need
	str = new (std::nothrow) char[strlen(buff) + 1];

	if (str == nullptr) {
	
		str = buff;
		return;
	}

	//taking everything from the buffer
	strcpy(str, buff);

	delete[] buff;

}


//task10
const unsigned int LETTERS_COUNT = 26;

void mostCommonAlpha(const char* str) {

	if (str == nullptr)
		return;

	size_t timesOcc[LETTERS_COUNT] = { 0, }; //how many times each 
	//letter occurs
	//mapping index 0 - 'a'
	//index 1 - 'b' and etc

	size_t i = 0;

	while (str[i] != '\0') {

		if (isAlpha(str[i]))
			timesOcc[tolower(str[i]) - 'a']++;
		//counts the current letter by adding one
		//on its index in the array
		i++;
	}

	//now the task is to find a maximum in an array

	size_t maxIndex = 0;
	for (size_t i = 1; i < LETTERS_COUNT; i++)
		if (timesOcc[maxIndex] < timesOcc[i])
			maxIndex = i;

	//re-mapping to find which char that is 
	std::cout << char(maxIndex + 'a')
		<< " times : " << timesOcc[maxIndex];

}


int main() {

	//task1 test
	if (isAlpha('A'))
		std::cout << "A is a letter!!!\n\n";


	//task2 test
	if (isDigit('3'))
		std::cout << "3 is a digit (and the best mark, also)!!!\n\n";


	//task3 test
	char toL[] = "abcd578ABCD";

	std::cout << "string before toLower : " << toL << '\n';
	toLower(toL);
	std::cout << "string after toLower : " << toL << "\n\n";


	//taks4 test
	char toCh[] = "a*b*c*d";

	char ch = '*';
	char sp = '1';

	std::cout << "string before change { " << ch << " -> " << sp 
		<< " } is " << toCh << '\n';
	changeSpSymbol(toCh, ch, sp);
	std::cout << "string after change : " << toCh << "\n\n";

	//task5 test
	std::cout << "the sting 1234 is as a number is : " << m_atoi("1234") << '\n';

	int res = 0;
	std::cout << "the sting -5678 is as a number is : ";
	res = m_atoi("-5678");
	std::cout << res << "\n\n";

	//task6 test
	const char* pl = "a1b1a";
	if (isPalindrome(pl))
		std::cout << pl << " is a palindrome!\n";

	const char* pl2 = "abba";
	if (isPalindrome(pl2))
		std::cout << pl2 << " is a palindrome!\n";

	const char* pl3 = "abcvba";
	if (!isPalindrome(pl3))
		std::cout << pl2 << " is not a palindrome!\n\n";

	//task7 test
	char rev[] = "readMeBackWords";
	std::cout << rev << " reversed is ";
	reverse(rev);
	std::cout << rev << "\n\n";

	//taks8 test
	const char* toAppend = "someTextToAppend";

	char* myText = new (std::nothrow) char[8];

	if (myText == nullptr)
		return -1;

	strcpy(myText, "my_Text");

	std::cout << myText << " after append is ";

	if (dynamicConcat(myText, toAppend))
		std::cout << myText;
	else
		std::cout << "memory issues!";

	delete[] myText; //release the mem

	std::cout << "\n\n";

	const char* cpt = "AlphaBetaGamaYou";

	char* dynCpt = new char[strlen(cpt) + 1];
	strcpy(dynCpt, cpt);

	std::cout << "the string before compact : " << dynCpt << '\n';
	compact(dynCpt);
	std::cout << "the string after compact : " << dynCpt << "\n\n";
	
	delete[] dynCpt;

	const char* cAlpha = "inThisWordTheMostCommonLetterIS";

	std::cout << "the most common letter in \\"
		<< cAlpha << "\\ is : \n";

	mostCommonAlpha(cAlpha);


	return 0;
}