/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   scopes.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Declare/define functions. Function scopes.
 */

#include <iostream>

// here is the zone we call the global scope

const int FORCE = 42; // the "FORCE" can be seen from each scope below

// declaring the function do_it, so it can be called from all other functions below,
// and it's definition can be done wherever we want - before/after main, before/after other functions
void do_it();

// each function defines its own scope
void use_the_force(int jedi_knight) {
    // jedi_knight and light_saber are seen as local variables
	int light_saber = 35;
	// here we can 'see' all global defined constants and variables
	// All locals are destroyed
	// after leaving the function /when the function ends/

	jedi_knight += FORCE; // the 'jediKnight' can 'see' the 'FORCE'

	jedi_knight += light_saber; // and each variable in the current scope

	std::cout << "Jedi's power: " << jedi_knight << std::endl;

    // we also can call all previously defined (or at least declared) functions
	do_it();

    // wrong! - another_happy_landing is neither previously defined nor declared
	// another_happy_landing();
}

void another_happy_landing() {

    std::cout << "Well done, Anakin" << std::endl;
}

void do_it() {

    std::cout << "Dew it!" << std::endl;
}

// the main function like each other function
// has its own scope
int main() {
    // a local variable
	int jedi_master = 11;

	// all the stuff from the global scope can be "seen" here
	jedi_master += FORCE;

    // we can call use_the_force with "jedi master" as parameter
	use_the_force(jedi_master);

	// the statements have their own scopes too
	// in these scopes we can see everything from
	// the scope above the statement
	if (true) {
		// the padawan is created and
		// lives only in the current scope
		int padawan = 1;
		padawan += jedi_master; // the padawan can 'see' the 'jedi_master'
		// we can call use_the_force with "padawan" as parameter
        use_the_force(jedi_master);
    } // <--- here the scope ends and the padawan gets destroyed

	// jedi_master += padawan; //problem here the padawan doesn't exist

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

    // the function is previously defined
	another_happy_landing();

	return 0;
}
