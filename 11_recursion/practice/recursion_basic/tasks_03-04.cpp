#include <iostream>

/*************** Task 3 ***************/
// print the binary representation of a number
// "actual function"
void print_bits_rec(unsigned int number, unsigned int position) {
	
	unsigned int mask = 1 << (position - 1);
	std::cout << ((number&mask) ? "1" : "0");
	
	if (position == 1)
		return;
	else
		return print_bits_rec(number, position - 1);
}

// example of a "wrapper function"
// "wrapper function" is a function which wraps another function (in our example the recursive one). 
// It's essentially another function which calls the actual function.
void print_bits(unsigned int number) {

	unsigned int position = sizeof(unsigned int) * 8; 
	return print_bits_rec(number, position);
}

/*************** Task 4 ***************/
// print the number of zeros and ones in the binary representation of a number
// main logic
void count_bits_rec(unsigned int number, unsigned int position, int &zeroes, int &ones) {
	
	unsigned int mask = 1 << (position - 1);
	((number&mask) ? ones++ : zeroes++);
	
	if (position == 1)
		return;
	
	else
		return count_bits_rec(number, position - 1, zeroes, ones);
}

void count_bits(unsigned int number) {
	
	int zeroes = 0;
	int ones = 0;
	unsigned int position = sizeof(unsigned int) * 8;
	count_bits_rec(number, position,zeroes,ones);
	std::cout << "In number: " << number << " we have " << zeroes << " zeroes and " << ones << " ones! \n";
 }

int main() {

	unsigned int number;
	std::cin >> number;
	// task_03
	print_bits(number);

	std::cout << std::endl;

	// task_04
	count_bits(number);
	std::cout << std::endl;

	return 0;
}
