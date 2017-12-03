#include<iostream>


int main() {

	int pointedVar = 10; //simple variable

	int * pInt; // a pointer to int called 'pInt'
	//we don't know where the pointer points to
	//so using it can be dangerous

	//the right way to set the pointer to point 'nowhere'
	pInt = NULL; // or
	pInt = nullptr;

	

	//each pointer will have the same size
	//(depending on which the OS platform is)
	//because in each pointer we hold an address
	//this address is where the pointed object is
	//in the memory
	
	char* pChar;

	if (sizeof(pInt) == sizeof(pChar))
		std::cout << "wow the same size, which in BYTES is "
		<< sizeof(pChar) << std::endl;


	pInt = &pointedVar; //now pInt points the pointedVar
						//its is achieved by using operator = 
						//to tell the pointer where to point 
						//and operator& to take the address of the pointedVar

	std::cout << "the address of the pointed variable is : 0x" << &pointedVar 
		<< "\nand its value : " << pointedVar << std::endl;


	//the pointers are also variables, so they are stored
	//into addresses for the memory space
	std::cout << "the address of the pointer is : 0x"
		<< &pInt << std::endl;

	std::cout << "the address where the pointer points to : 0x"
		<< pInt << std::endl;


	//use * to dereference the pointer / to take the value of the pointed object
	std::cout << "the value of the pointed object by the pointer is : "
		<< *pInt << std::endl;

	//we can manipulate the pointedVar through the pointer

	*pInt = 11;

	std::cout << "wow, the value of the pointed variable is now changed to "
		<< pointedVar << std::endl;



	int* pOtherPointer = pInt; // we can create another pointer		
							  //and to make it point the same place

	if (pOtherPointer == pInt) //we can check if the two pointer are pointing the same place
		std::cout << "wow, two pointers pointing the same address\n";

	pInt = NULL; // now pInt points 'nowhere'

	pointedVar = 42; // changing the variable's value

	std::cout << "pointedVar == " << pointedVar;
	std::cout <<" \\\\ *pOtherPointer == " << *pOtherPointer; //prints 42

	return 0;
}								
