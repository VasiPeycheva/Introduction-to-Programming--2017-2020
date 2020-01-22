/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   basic_example.cpp
 * @author Ivan Filipov
 * @date   01.2020
 * @brief  Example implementation of calculator using function pointers.
 */

#include<iostream>

// typedef for function pointers has special meaning:
// operation_fptr now is a type - a pointer to function, that
//                                takes two ints and returns int
// typedef makes our code cleaner and easier to maintain
typedef int(*operation_fptr)(int, int);

int add(int x, int y) {

	return x + y;
}

int subtract(int x, int y) {

	return x - y;
}

int mul(int x, int y) {

	return x * y;
}

// will return a pointer to function
// depending on the character we have received
operation_fptr select_operation(char op_code) {

	switch (op_code) {
	case '+' :
		return add;
	case '-' :
		return subtract;
	case '*' :
		return mul;
	default:
		return nullptr; // unknown operation
	}
}

// calculate an operation on lhs and rhs
int eval(char op_code, int lhs, int rhs) {

    // which function to be applied
	operation_fptr operation = select_operation(op_code);

	if (operation == nullptr) {
		std::cout << "Invalid operation, can't evaluate!" << std::endl;
		return 0;
	}

	// the real evaluation is done here,
	// by invoking the right function though the pointer
	return operation(lhs, rhs);
}

int main() {

	std::cout << "*********Usage*********"    << std::endl
		<< "please use the following format:" << std::endl
		<< "<operand1> <operation> <operand2>"<< std::endl
		<< "example : 5 + 3"                  << std::endl
		<< "**********************"
		<< std::endl
		<< std::endl
		<< std::endl;

	int op1, op2, result;
	char op_code, choice;

	while (true) {

		std::cout << "Now enter the wanted calculation:" << std::endl;
		std::cin >> op1 >> op_code >> op2;

		result = eval(op_code, op1, op2);
		std::cout << "Result = " << result << std::endl;

		std::cout << "New calculation - (y\\n)?" << std::endl;
		std::cin >> choice;

		if (choice == 'n' || choice == 'N')
			break;
	}

	std::cout << "Goodbye!" << std::endl;
	return 0;
}
