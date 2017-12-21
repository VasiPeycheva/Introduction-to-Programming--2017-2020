#include<iostream> //cin , cout , fixed
#include<iomanip> //setprecision
#include<math.h> //sqrt

//using typedef we can call a standard type with another name
typedef unsigned long long int ull_int;


//task 1 function
int max(int a, int b) {

	return (a > b) ? a : b;
}

//task 2 function
int abs(int x) {

	return (x >= 0) ? x : -x;
}

//task 3
ull_int pow(unsigned int n,unsigned int k) {

	if (k == 0)
		return 1; //if we enter here, the function ends

	ull_int result = n;

	for (unsigned int i = 1; i < k; i++)
		result *= n;
	
	return result;
}

//task 4 using euclidean's algorithm with divisions
unsigned int gcd(unsigned int a,unsigned int b) {

	int temp;

	while (b != 0) {

		temp = a % b;
		a = b;
		b = temp;

	}

	return a;
}

unsigned int fib(unsigned int n) {

	//invalid case
	if (n == 0)
		return 0;

	//basic cases
	if (n == 1 || n == 2)
		return 1;

	unsigned int fib1 = 1;
	unsigned int fib2 = fib1;

	//unsigned int fibNext; //can be done without third variable
	n -= 2;
	while (n--) {

		//fibNext = fib1 + fib2; //alternative approach
		//fib1 = fib2;
		//fib2 = fibNext;

		fib2 = fib1 + fib2;
		fib1 = fib2 - fib1;

	}

	return fib2;
}


//task 6
bool isPrime(unsigned int n) {

	if (n < 2)
		return true;

	int sq = sqrt(n);

	for (int i = 2; i < sq; i++)
		if (n % i == 0)
			return false;

	return true;

}

//task 7 function
unsigned int divs(unsigned int dividend, unsigned int divisor) {

	if (divisor == 0 || dividend < divisor )
		return 0;

	unsigned int cnt = 0;

	while (dividend % divisor == 0) {

		dividend /= divisor;
		cnt++;
	}

	return cnt;
}

//task 8
double circleArea(double r) {

	const double pi = 3.14;

	return pi*r*r;

}

//task 9
void printOutput(int m) {

	std::cout << "the max entered number is " << m;

}

void readInputN() {

	unsigned int n;

	std::cin >> n;

	int curNum, curMax = INT_MIN; //INT_MAX is a constant 
								  //defined in limits.h

	do {

		std::cin >> curNum;

		curMax = max(curMax, curNum);
	
	} while (--n);

	printOutput(curMax);
}



//no return value -> return type 'void'
void printGreetings() {

	std::cout << "Hello, these are our examples "
	             "for function usage in C++\n\n";


}


int main() {

	//task 0 print greetings
	printGreetings();

	//task 1 function usage 
	int a, b;
	
	std::cout << "enter a and b, then you will see the greater one! \n";
	std::cin >> a >> b;

	std::cout << "\nmax(" << a << ',' << b << ")="
			  << max(a,b) << '\n';

	//task 2 function usage
	int myX;

	std::cout << "\nenter x, then you will see abs(x) \n";
	std::cin >> myX;

	std::cout << "\nabs(" << myX << ")= "
		<< abs(myX) << '\n';

	//task 3 function usage
	int base,exp;

	std::cout << "\nenter base and exp, then you will see pow(base,exp) \n";
	std::cin >> base >> exp;

	std::cout << "\npow(" << base << " , " << exp
		<< ")=" << pow(base, exp) << '\n';

	//task 4 function usage
	unsigned int first, second;

	std::cout << "\nenter two numbers, then you will see GCD(first,second) \n";
	std::cin >> first >> second;

	std::cout << "\nGCD(" << first << " , " << second
		<< ")=" << gcd(first, second) << '\n';

	//task 5 function usage
	unsigned int fibN;

	std::cout << "\nenter n, then you will see n-th Fibonacci sequence member \n";
	std::cin >> fibN;

	std::cout << "\nfib(" << fibN << ")= "
		<< fib(fibN) << '\n';

	//task 6 function usage
	unsigned int num;

	std::cout << "\nenter a number, then you will see if the number is prime\n";
	std::cin >> num;

	if (isPrime(num))
		std::cout << num << " is prime!\n";
	else
		std::cout << num << " is compose!\n";

	//task 7 function usage
	unsigned int dividend, divisor;

	std::cout << "\nenter dividend and divisor , then you will see how \n"
		 "many times the divisor divides the dividend without remainder\n";
	std::cin >> dividend >> divisor;

	std::cout << "\ndiv(" << dividend << " , " << divisor
		<< ")=" << divs(dividend, divisor) << '\n';

	//task 8 function usage
	double rad;

	std::cout << "\nenter radius, then you will see the area of circle with this radius \n";
	std::cin >> rad;

	std::cout << "\circleArea(" << rad << ")= " << std::fixed
		<< std::setprecision(2) << circleArea(rad) << '\n';

	//task 9 function usage
	
	std::cout << "\nenter a number N, then another N numbers," 
		"after that you will see the max one\n";
	readInputN();

	return 0;
}

