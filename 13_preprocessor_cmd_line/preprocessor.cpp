/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   preprocessor.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  Some use cases of the C preprocessor.
 * @see    https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp.html#SEC_Top
 */

//include is a preprocessor's directive, which tells
// "just paste this file's content"
#include <iostream>

// macro as a constant
#define MAX_SIZE 24
int arr[MAX_SIZE]; // we can use it as an ordinary constant

// if directive
#if MAX_SIZE > 16 // MAX_SIZE should be defined, only constant expressions here are allowed
// redefining
    #undef MAX_SIZE
    #define MAX_SIZE 16

    int arr1[MAX_SIZE];
#endif

// macros as functions
// Notice the large amount of brackets used
// in order to do the right job, if
// expression is passed not only a variable.
#define min(a,b) (((a) > (b)) ? (b) : (a))

#define max(a,b) (((a) > (b)) ? (a) : (b))

#define sq(x) (x)*(x)

#define bug_sq(x) x*x // try this with bug_sq(x + 3), what will happen?

// multi-line macros
#define abs(x) \
		((x > 0) ? \
		(x) : \
		((-1)*(x)))

// just a definition (see below for usage)
#define DEBUG

// argument to string macro
#define to_string(x) #x

// concatenation macro
#define concat(x,y) x##y

int main() {

// conditional include
#ifdef DEBUG // if defined
	// will include these lines if only
	// DEBUG is defined
	std::cout << "Debug mode on" << std::endl;
#endif // DEBUG

	int a = 10, b = 15;
	int x = -11;

	// macros function usage
	std::cout << to_string(MAX_SIZE) << MAX_SIZE << std::endl;
	std::cout << to_string(max(a, b) = ) << max(a, b) << std::endl;
	std::cout << to_string(min(a, b) = ) << min(a, b) << std::endl;
	std::cout << to_string(abs(x) = ) << abs(x) << std::endl;
	std::cout << to_string(sq(x) = )  << sq(x)  << std::endl;

	std::concat(c, out) << "wow how is this even possible?!\n";
	int cat_num = concat(10, 11);
	std::cout << cat_num;

	return 0;
}
