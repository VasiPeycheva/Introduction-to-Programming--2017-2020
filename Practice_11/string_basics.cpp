#include<iostream>

//read below about this functions
//we are going to use these form the <string.h>
//but the point here is to see how they work

//iostream includes string.h, so we should have different names
//for these functions something m_ for 'my version of this function ...'

//the examples are at -----passing strings as function arguments ------
size_t m_strlen(const char*);
char* m_strcpy(char*, const char*);
int m_strcmp(const char*, const char*);
char* m_strcat(char*, const char*);



int main() {

	///----------------------CREATING -----------------------------

		//we have multiple ways of creating a string 

		//as array of chars with static size (in stack memory)
	const char str[] = { 's','t','r','i','n','g','\0' };

	//const char here means that we can't change the 
	//contain of the string

	//as array of characters  with dynamic size (in heap memory)
	const int size = 6; //the number of symbols 
	char* dynStr = new (std::nothrow) char[size + 1]; //ever + 1 for the '\0'

	if (dynStr) {

		dynStr[0] = 's'; //writing to a cell
		dynStr[1] = 't';
		dynStr[2] = 'r';
		dynStr[3] = 'i';
		dynStr[4] = 'n';
		dynStr[5] = 'g';
		dynStr[6] = '\0'; //!!!! don't forget about the terminating null

	}

	//free the memory
	delete[]dynStr;

	//as a pointer to a static allocated literal
	const char* litStr = "literal String"; //there is a hidden '\0' symbol
										 //at the end of this literal

	//same as 
	const char litStr2[] = "literal String"; //there is a hidden '\0' symbol
	
	//but...
	char smth[] = "something";
	char* smt = "something";
	//are different because in the second we are pointing to a static
	//memory and we can't change it, but in the first the memory is allocated
	//for us in the stack


	//we can have an array of strings : 
	const char* listOfWords[] = { "firstWord", "second String" , "and etc" };


///----------------------WRITING TO OUTPUT -----------------------------

	//we can print each symbol of the string
	int i = 0;

	while (litStr2[i] != '\0') //until the terminating null
		std::cout << litStr2[i++]; //outputs litStr2[i] and then i = i + 1
		
	std::cout << std::endl;
	//or we can just output the whole string using 

	std::cout << litStr2; //it will do the same thing the upper lines do
	std::cout << std::endl;

	//to output a word form our list : 

	std::cout << listOfWords[2]; //prints "and etc"
	std::cout << std::endl;

///----------------------READING FROM INPUT -----------------------------

	//the normal reading with cin >> can be dangerous, because
	//we don't know how many symbols will be entered form the standart input
	//before ' ' or \n, so we don't know if our allocated memory is enough
	//take the whole input 

	//for example

	/* 
	char wrong_str[3]; // allocating memory for 12 chars

	std::cin >> wrong_str; // someone enters "abcd"
	which writes after our buffer and our program will die :(

	*/
	
	//so the proper way is :

	const int max_size = 1024;

	char buff[max_size];

	//will read a whole line to \n or maximum max_size - 1 chars
	//adds '\0' to our string

	std::cout << "input a string : \n";
	std::cin.getline(buff, max_size);

	std::cout << "\nresult : " << buff << std::endl;

	//if we want to reuse this buffer
	//aka to clean it, we can use

	memset(buff, 0, max_size); //this will write 0's in each cell of our buffer

	//now we can read with getline up to a given character 

	char upToThisChar = ' ';

	std::cout << "\ninput a string : \n";
	std::cin.getline(buff, max_size, upToThisChar); //will take the first word form the input
	std::cout << "\nresult : " << buff << std::endl;


///----------------------PASSING AS FUNCTION ARGUMENTS -----------------------------

	std::cout << "\nbasic functions examples : \n";

	const char* dogFirstName = "Goofy";
	const char* dogSecondName = "Goof";

	const size_t fullNameSize = 32;

	char fullName[fullNameSize];

	memset(fullName, 0, fullNameSize);

	std::cout << "the first name " << dogFirstName
		<< " has length :" << m_strlen(dogFirstName);

	std::cout << "\nthe full name is empty" << fullName;

	std::cout << "\nthe full name after coping the first name :\n"
		<< m_strcpy(fullName, dogFirstName);
	
	std::cout << std::endl;

	std::cout << "\nthe full name after concatenating the second name :\n"
		<< m_strcat(fullName, dogSecondName);

	std::cout << "\n\nthe compare between first and second name give us :\n";

	int res = m_strcmp(dogFirstName, dogSecondName);

	if (res > 0)
		std::cout << "that the first name is lexicographical first\n";

	if(res == 0)
		std::cout << "that the two names are lexicographical equal\n";

	if(res < 0)
		std::cout << "that the second name is lexicographical first\n";


	return 0;
}


//gives us the length of a string
//more at : http://www.cplusplus.com/reference/cstring/strlen/
size_t m_strlen(const char* str){

	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return len;

}


//copies the contain form source into the destination
//more at http://www.cplusplus.com/reference/cstring/strcpy/
char* m_strcpy(char* dest, const char* src){

	size_t i = 0;

	while (src[i]) { //same as src[i] != '\0'
		
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}

//compares two strings lexicographical 
//returns < 0 if the rhs is the bigger one
// 0 if both are equal
// > 0 if the lhs is the bigger one

//more at : http://www.cplusplus.com/reference/cstring/strcmp/
int m_strcmp(const char* lhs, const char *rhs){

	size_t i;

	for (i = 0 ; lhs[i] != '\0' && lhs[i] == rhs[i]; i++)
		;

	return (int)(lhs[i] - rhs[i]);

}

//concatenates the contain of destination with the source
//aka append operation

//more at : http://www.cplusplus.com/reference/cstring/strcat/
char* m_strcat(char* dest, const char* src){

	size_t dest_i = strlen(dest); 

	size_t i = 0;

	while (src[i] != '\0')
		dest[dest_i++] = src[i++]; // dest[dest_i] = src[i], then dest_i ++ , i ++
								   
	dest[dest_i] = '\0';

	return dest;

}
