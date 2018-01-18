#include<iostream>

//an example for using queue recursion 
unsigned short cntOnes(unsigned int num, unsigned short it) {

	if (it == 0)
		return num & 1;

	return bool(num & (1 << it)) +
		cntOnes(num, --it); //it-- leads to stack overflow why?

}


void printBitCount(unsigned int num) {

	unsigned short nOnes = cntOnes(num, sizeof(unsigned int) * 8 - 1);


	std::cout << "\nIn number: " << num
		<< " we have : " << sizeof(unsigned int) * 8 - nOnes << " zeros "
		<< "and " << nOnes << " ones!\n";

}



void printBits_rec(unsigned int number, unsigned int it){
	
	std::cout << ((number & (1 << it)) ? "1" : "0");

	if (it == 0)
		return;
	else
		return printBits_rec(number, --it);
}

//the wrapper
void printBits(unsigned int number){

	return printBits_rec(number, sizeof(unsigned int) * 8 - 1);
}

int main() {

	unsigned int n = 1027;

	printBits(n);

	printBitCount(n);

	return 0;
}