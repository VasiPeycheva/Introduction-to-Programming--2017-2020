#include<iostream>

//the most basic example 
void(*foo)();

//a simple function
int sum(int x, int y) {

	return x + y;
}

int main() {

	//a pointer to function which takes two integers 
	//and returns an integer
	int(*fptrSum)(int, int);

	//now fptrSum can point to the function "sum"
	fptrSum = sum; //we can skip the '&' from 
					//fptrSum = &sum;

	//now we can invoke the function through the pointer
	std::cout << fptrSum(1, 2);

	return 0;
}