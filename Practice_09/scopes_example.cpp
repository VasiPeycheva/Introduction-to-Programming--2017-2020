#include<iostream>

//here is the zone we call the global scope

const int FORCE = 42; //the 'FORCE' can be seen from each 
					  //each scope below
					 

//each function defines its own scope
void useTheForce(int jediKnight) {

	int lightSaber = 35;
	//here we can 'see' all global defined constants and variables
	//plus all the function parameters

	//the parameter jediKnight and 
	//the local defined variable lightSaber 
	//live only
	//in the current scope.
	//They are destroyed
	//after leaving it / when the function ends / 

	jediKnight += FORCE; // the 'jediKnight' can 'see'
						 // the 'FORCE'

	jediKnight += lightSaber; // and each variable in the current scope 

}

//the main function like each other function
//has its own scope
int main() {

	int jediMaster = 11;

	//are global defined constants, variables
	//and every function can be 'seen' from here

	jediMaster += FORCE;

	useTheForce(jediMaster); // calling the function 'useTheForce'
							 //with jediMaster as parameter results in :
							 //jediMaster's value is copied into the function's
							 //jediKnight variable, and inside the function scope
							 //we can see only the copy and work with it through
							 //jediKnight variable

	//the statements have their own scopes too
	//in these scopes we can see everything from
	//the scope above the statement
	if (true) {

		//the padawan is created and
		//lives only in the current scope
		int padawan = 1;

		padawan += jediMaster; // the padawan can 'see' the 'jediMaster'

		useTheForce(padawan); // and use the force too
	} //<--- here the scope ends and the padawan gets destroyed

	//jediMaster += padawan; //problem here the padawan doesn't exist
	 

	int destroyers = 10;
	for (int clones = 10; clones < 20; clones++) {

		//the clones variable lives only in the for loop's
		//scope

		int droids = 5; // the variable droids will be created
					  // and destroyed in each step of the loop
					 //maybe we don't want to do so
					//and the proper approach when we want
					//to use a variable in each step of the loop
					//is to create it above the loop just like 
					//the variable 'destroyers'

		if (destroyers + droids > clones)
			std::cout << "Separatists win!\n";
		else
			std::cout << "The Republic wins!\n";

	}	

	return 0;

}