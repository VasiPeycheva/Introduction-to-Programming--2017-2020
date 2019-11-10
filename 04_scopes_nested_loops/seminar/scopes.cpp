/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   scopes.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  An example, which shows from where,
 *         which variable we can "see".
 */

#include <iostream>

// here is the zone we call the global scope

const int FORCE = 42; // the "FORCE" can be seen from each scope below

// the main function like each other function
// has its own scope
int main() {
    // a local variable
	int jedi_master = 11;

	// all the stuff from the global scope can be "seen" here
	jedi_master += FORCE;

	// the statements have their own scopes too
	// in these scopes we can see everything from
	// the scope above the statement
	if (true) {
		// the padawan is created and
		// lives only in the current scope
		int padawan = 1;
		padawan += jedi_master; // the padawan can 'see' the 'jedi_master'
    } //<--- here the scope ends and the padawan gets destroyed

	// jedi_master += padawan; <- problem here the padawan doesn't exist in the current scope


	int destroyers = 10;
	for (int clones = 10; clones < 20; clones++) {
		// the clones variable lives only in the for loop's scope

		int droids = 5;  /* the variable droids will be created
                            and destroyed in each step of the loop
                            maybe we don't want to do so
                            and the proper approach when we want
                            to use a variable in each step of the loop
                            is to create it above the loop just like
                            the variable 'destroyers' */

		if (destroyers + droids > clones)
			std::cout << "Separatists win!" << std::endl;
		else
			std::cout << "The Republic wins!" << std::endl;
	}

	return 0;
}
