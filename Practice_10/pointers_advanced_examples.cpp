#include<iostream>

//the function takes two references 
//'other' names for the given arguments
//the function will change the arguments themselves
void swap(int& first, int& second) {

	int temp = first;
	first = second;
	second = temp;

}

//the references in C++ are syntax sugar for int* const 
//a constant pointer a.k.a pointer which can points only one place


int main() {

	int someVar = 42;
	int const someConstVar = 55;

	int* pVar = &someVar; //ordinary pointer
	//check the previous practice for more info


	const int* pConstVar = &someConstVar; //a pointer to constant
	pConstVar = &someVar; //could point to a non-constant variable
						  //have the meaning this variable will not be changed
						  //through me

	//the compiler knows that the pointed variable can't be changed 
	//*pConstVar = 11; // wrong !!!
	
	int* const constpVar = &someVar; //a constant pointer

	*constpVar = 11; // OK , but ....

	int someAtherVar = 43;

	//constpVar = &someAtherVar; // // wrong can't be redirected

	//the ultimate constant pointer to constant
	const int* const pConstToConst = &someConstVar;
	//now only read operations are available through this pointer



	//references check the function below

	//int& refVar; //wrong the other 'name' should be given  
	int& refVar = someVar;


	std::cout <<"address of ref 0x" <<  &refVar << '\n';

	std::cout << "address of var 0x" << &someVar << '\n';

	int a = 10, b = 20;

	std::cout << "a = " << a << "b = " << b << '\n';
	swap(a, b);
	std::cout << "a = " << a << "b = " << b << '\n';

	return 0;
}