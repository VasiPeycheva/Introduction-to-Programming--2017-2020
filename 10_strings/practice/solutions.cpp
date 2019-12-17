#include <iostream> //cin, cout
#include <string.h> // strlen , strcat ///

// #include <ctype.h> isalpha, isdigit, islower etc could be found,
// it is a part of string.h


// task_01 
// more at : http://www.cplusplus.com/reference/cctype/isalpha/
bool is_alpha(char c) {

	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// task_02
bool is_digit(char c) {

	return c >= '0' && c <= '9';
}


// task_03 
void to_lower(char* str) {

	// protects our function
	// from invalid usage
	if (str == nullptr)
		return;

	// the standard way of iterating a string
	size_t i = 0;

	// loop until the terminating symbol
	while (str[i] != '\0') {

		if (isupper(str[i]))		// using isupper from ctype.h
			str[i] += 'a' - 'A';	// using the fact that the lower letters are before
									// the upper ones, so changing is  just 
									// 'moving around into the ASCII table'
		i++;
	}
}

// task_04
void change_sp_symbol(char* str, char to_change, char change_with) {

	if (str == nullptr)
		return;

	size_t i = 0;

	while (str[i] != '\0') {
		
		if (str[i] == to_change)
			str[i] = change_with;

		i++;
	}
}

// task_05 !!! atoi already included by string.h !!! 
int m_atoi(const char* str) {	// we will not change the string's
								// contain so passing it by const 
								// is the right way to go

	// will not compile in debug mode when nullptr or NULL passed,
	// but just to insure everything 

	if (str == nullptr)
		return 0; // maybe

	int result = 0;

	int sign = 1;

	if (*str == '-') { // the first char is -
		sign = -1;
		str++; // moves the pointer one position forward
	}

	size_t i = 0;

	while (str[i] != '\0') {

		result *= 10;			// a new space at the end of the number
		result += str[i] - '0';	// putting the new digit at the end

		i++;
	}

	return result * sign;
}


// task_06
bool is_palindrome(const char* str) {

	if (str == nullptr)
		return false;

	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2)						// looking at the front and at the end
		if (str[i] != str[len - (i + 1)])	// the last element is on index str[len-1]
			return false;
		else
			i++;

	// if the first half is the reversed second
	return true;

}

// task_07
void reverse(char* str) {

	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2) { //looking at the front and at the end
		std::swap(str[i], str[len - (i + 1)]);
		i++;
	}

}


// task_08
// returns false if there was some kind of memory problem
bool dynamic_concat(char*& dest, const char* src) { // the dest pointer will be redirected, 
													// so taking it by ref is essential

	char* new_mem_buff = new (std::nothrow) char[strlen(dest) + strlen(src) + 1]; 
	// enough memory for both strings' contain + '\0'

	if (new_mem_buff == nullptr)
		return false;

	strcpy(new_mem_buff, dest); // copy the first part
	strcat(new_mem_buff, src);  // appends the second part

	// clear the unneeded memory
	delete[] dest;

	dest = new_mem_buff; // redirecting the pointer from main/other function

	return true;
}					


// task_09
bool is_vowel(char c) {

	if (!is_alpha(c))
		return false;

	c = tolower(c);

	return c == 'a' || c == 'e' || 
		   c == 'i' || c == 'u' || 
		   c == 'o';
	
}

void compact(char*& str) {	// will redirect str -> reference!

	if (str == nullptr)
		return;

	char* buff = new (std::nothrow) char[strlen(str) + 1]; //alloc a buff

	if (buff == nullptr)
		return;

	size_t i = 0, i_buff = 0;

	while (str[i] != '\0') {

		if (is_vowel(str[i])) { // skipping the vowels
			i++;
			continue;
		}

		//copying other symbols
		buff[i_buff++] = str[i++];
	}

	buff[i_buff] = '\0';

	delete[] str; // we don't need this mem anymore

	// new memory as we need
	str = new (std::nothrow) char[strlen(buff) + 1];

	if (str == nullptr) {
	
		str = buff;
		return;
	}

	// taking everything from the buffer
	strcpy(str, buff);

	delete[] buff;

}

const unsigned int LETTERS_COUNT = 26;
// task_10
void most_common_alpha(const char* str) {

	if (str == nullptr)
		return;

	size_t times_occ[LETTERS_COUNT] = { 0, }; // how many times each 
	// letter occurs
	// mapping index 0 - 'a'
	// index 1 - 'b' and etc

	size_t i = 0;

	while (str[i] != '\0') {

		if (is_alpha(str[i]))
			times_occ[tolower(str[i]) - 'a']++;
		// counts the current letter by adding one
		// on its index in the array
		i++;
	}

	// now the task is to find a maximum in an array

	size_t max_index = 0;
	for (size_t i = 1; i < LETTERS_COUNT; i++)
		if (times_occ[max_index] < times_occ[i])
			max_index = i;

	// re-mapping to find which char that is 
	std::cout << char(max_index + 'a')
		<< " times : " << times_occ[max_index];
}


int main() {

	std::cout << "-----------Task 1-----------" << std::endl;
	if (is_alpha('A'))
		std::cout << "A is a letter!!!" << std::endl;


	std::cout << "-----------Task 2-----------" << std::endl;
	if (is_digit('3'))
		std::cout << "3 is a digit (and the best mark, also)!!!" << std::endl;


	std::cout << "-----------Task 3-----------" << std::endl;
	char toL[] = "abcd578ABCD";

	std::cout << "string before toLower : " << toL << std::endl;
	to_lower(toL);
	std::cout << "string after toLower : " << toL << std::endl;


	std::cout << "-----------Task 4-----------" << std::endl;
	char to_ch[] = "a*b*c*d";

	char ch = '*';
	char sp = '1';

	std::cout << "string before change { " << ch << " -> " << sp 
		<< " } is " << to_ch << std::endl;
	change_sp_symbol(to_ch, ch, sp);
	std::cout << "string after change : " << to_ch << std::endl;

	std::cout << "-----------Task 5-----------" << std::endl;
	std::cout << "the sting 1234 is as a number is : " << m_atoi("1234") << std::endl;

	int res = 0;
	std::cout << "the sting -5678 is as a number is : ";
	res = m_atoi("-5678");
	std::cout << res << std::endl;

	std::cout << "-----------Task 6-----------" << std::endl;
	const char* pl = "a1b1a";
	if (is_palindrome(pl))
		std::cout << pl << " is a palindrome!" << std::endl;

	const char* pl_2 = "abba";
	if (is_palindrome(pl_2))
		std::cout << pl_2 << " is a palindrome!" << std::endl;

	const char* pl_3 = "abcvba";
	if (!is_palindrome(pl_3))
		std::cout << pl_3 << " is not a palindrome!" << std::endl;

	std::cout << "-----------Task 7-----------" << std::endl;
	char rev[] = "read_me_back_words";
	std::cout << rev << " reversed is ";
	reverse(rev);
	std::cout << rev << std::endl;

	std::cout << "-----------Task 8-----------" << std::endl;
	const char* to_append = "some_text_to_append";

	char* my_text = new (std::nothrow) char[8];

	if (my_text == nullptr)
		return -1;

	strcpy(my_text, "my_text");

	std::cout << my_text << " after append is ";

	if (dynamic_concat(my_text, to_append))
		std::cout << my_text;
	else
		std::cout << "memory issues!";

	delete[] my_text; //release the mem

	std::cout << std::endl;

	std::cout << "-----------Task 9-----------" << std::endl;
	const char* cpt = "AlphaBetaGamaYou";

	char* dyn_cpt = new char[strlen(cpt) + 1];
	strcpy(dyn_cpt, cpt);

	std::cout << "the string before compact : " << dyn_cpt << std::endl;
	compact(dyn_cpt);
	std::cout << "the string after compact : " << dyn_cpt << std::endl;
	
	delete[] dyn_cpt;

	std::cout << "-----------Task 10-----------" << std::endl;
	const char* c_alpha = "inThisWordTheMostCommonLetterIS";
	std::cout << "the most common letter in \\"
		<< c_alpha << "\\ is : " << std::endl;

	most_common_alpha(c_alpha);

	return 0;
}
