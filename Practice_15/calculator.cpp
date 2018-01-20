#include<iostream>

int add(int x, int y) {

	return x + y;
}

int subtract(int x, int y) {

	return x - y;
}

int mul(int x, int y) {


	return x * y;
}

//makes our code cleaner and easier to maintain
typedef int(*fptrOperation)(int, int);


//will return a pointer to function
//depending on the character we have received
fptrOperation selectOperation(char opCode) {

	switch (opCode){
		
	case '+' : 
		return add;

	case '-' :
		return subtract;

	case '*' :
		return mul;

	default:
		return nullptr; //unknown operation
	}

}

int eval(char opCode, int lhs, int rhs) {

	fptrOperation operation = selectOperation(opCode);

	if (operation == nullptr) {

		std::cout << "invalid operation, can't evaluate!\n";
		return 0;

	}

	//the real evaluation is done
	//by invoking the right function by the pointer
	return operation(lhs, rhs);

}




int main() {
	
	std::cout << "*********Usage********* \n"
		<< "please use the following format : \n"
		<< "<operand1> <operation> <operand2>\n"
		<< "example : 5 + 3\n"
		<< "********************** \n\n\n";

	int op1, op2, result;
	char opCode, choice;

	while (true) {
		
		std::cout << "now enter the wanted calculation\n\n";
		std::cin >> op1 >> opCode >> op2;

		result = eval(opCode, op1, op2);

		std::cout << "result = " << result << '\n';

		std::cout << "new calculation? y\\n ? \n";

		std::cin >> choice;

		if (choice == 'n' || choice == 'N')
			break;

	}

	std::cout << "Goodbye!\n";
	return 0;
}