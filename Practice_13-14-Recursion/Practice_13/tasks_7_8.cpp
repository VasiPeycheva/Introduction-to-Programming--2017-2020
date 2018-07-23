#include<iostream>

//task7
//the actual recursive
//function
void printLine_rec(unsigned int k,unsigned int it, unsigned long long result) {

	std::cout << result << ' ';
	
	if (it < k)
		printLine_rec(k, it + 1, result * 10);

	std::cout << result << ' ';


}

//the wrapper
void printLine(unsigned int k) {

	printLine_rec(k, 1, 10);
}


//task 8 function
//just by following the recursive 
//definition of the algorithm
int gcd(int a, int b) {

	return (b == 0) ? a : gcd(b, a % b);
}


int main() {


	//task 7 output
	std::cout << "Enter a positive number k >= 1, k = ";
	unsigned int k;

	std::cin >> k;

	if (k < 1)
		std::cout << "cheater!\n";
	else {
		std::cout << "The line looks like : \n";
		printLine(k);
	}

	//task 8 output
	std::cout << "\n\nEnter two numbers :\n";

	int a, b;

	std::cin >> a >> b;

	std::cout << "gcd(" << a << ", " << b << ") = "
		<< gcd(a, b) << '\n';


	return 0;
}