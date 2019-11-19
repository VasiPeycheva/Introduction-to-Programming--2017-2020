/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for function tasks from practice 5.
  */

#include <iostream>
#include <iomanip>

#define _USE_MATH_DEFINES // should be added for M_PI's value
#include <cmath>   // sqrt()
#include <climits> // INT_MAX

// using typedef we can call a standard type with another name
// wherever we use 'ull_int' we mean unsigned long long int
typedef unsigned long long int ull_int;

// task_01
int max(int a, int b) {

	return (a > b) ? a : b;
}

// task_02
int abs(int x) {

	return (x >= 0) ? x : -x;
}

// task_03
ull_int powered(unsigned int n, unsigned int k) {

	if (k == 0) {
		return 1; // if we enter here, the function ends
	}

	ull_int result = n;

	for (unsigned int i = 1; i < k; i++) {
		result *= n;
	}

	return result;
}

// task_04 using Euclidean algorithm with divisions
unsigned int gcd(unsigned int a, unsigned int b) {

	unsigned int temp;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

// task_05
unsigned int fib(unsigned int n) {

	// invalid case
	if (n == 0)
		return 0;

	// basic cases
	if (n == 1 || n == 2)
		return 1;

	unsigned int fib1 = 1;
	unsigned int fib2 = fib1;

	// unsigned int fib_next; //can be done without third variable
	n -= 2;
	while (n--) {
		//fib_next = fib1 + fib2; // alternative approach
		//fib1 = fib2;
		//fib2 = fib_next;

		fib2 = fib1 + fib2;
		fib1 = fib2 - fib1;
	}

	return fib2;
}

// task_06
bool is_prime(unsigned int n) {

	if (n < 2) {
		return true;
	}

	int sq = sqrt(n);
	for (int i = 2; i < sq; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

// task_07
unsigned int divs(unsigned int dividend, unsigned int divisor) {

	if (divisor == 0 || dividend < divisor)
		return 0;

	unsigned int cnt = 0;

	while (dividend % divisor == 0) {
		dividend /= divisor;
		cnt++;
	}

	return cnt;
}

// task_08
double circle_area(double r) {

	return M_PI * r * r;
}

// task_09
void print_output(int m) {

	std::cout << "The max entered number is " << m << std::endl;
}

void read_inputs() {

	unsigned int n;

	std::cin >> n;
	if (n == 0) return; // return from function, without printing anything

	int cur_num;
    int cur_max = INT_MIN;
	do {
        --n;
		std::cin >> cur_num;
		cur_max = max(cur_max, cur_num);
	} while (n);

	print_output(cur_max);
}

int main() {

	// task 1 function usage
	std::cout << "-----------Task 1-----------" << std::endl;
	int a, b;
	std::cout << "Enter a and b, then you will see the greater one:" << std::endl;
	std::cin  >> a >> b;
	std::cout << "max(" << a << ',' << b << ") = "
              << max(a, b) << std::endl;

	// task 2 function usage
	std::cout << "-----------Task 2-----------" << std::endl;
	int x;

	std::cout << "Enter x, then you will see abs(x):" << std::endl;
	std::cin  >> x;
	std::cout << "abs(" << x << ") = " << abs(x) << std::endl;

	// task 3 function usage
	std::cout << "-----------Task 3-----------" << std::endl;
	int base, exp;
	std::cout << "Enter base and exp, then you will see pow(base,exp):" << std::endl;
	std::cin  >> base >> exp;
	std::cout << "pow(" << base << " , " << exp
              << ") = " << powered(base, exp) << std::endl;

	// task 4 function usage
	std::cout << "-----------Task 4-----------" << std::endl;
	unsigned int first, second;

	std::cout << "Enter two numbers, then you will see GCD(first,second):" << std::endl;
	std::cin  >> first >> second;
	std::cout << "GCD(" << first << ", " << second
              << ") = " << gcd(first, second) << std::endl;

	// task 5 function usage
	std::cout << "-----------Task 5-----------" << std::endl;
	unsigned int n_fib;

	std::cout << "Enter n, then you will see n-th Fibonacci sequence member:" << std::endl;
	std::cin  >> n_fib;
	std::cout << "fib(" << n_fib << ") = " << fib(n_fib) << std::endl;

	// task 6 function usage
	std::cout << "-----------Task 6-----------" << std::endl;
	unsigned int num;
	std::cout << "Enter a number, then you will see if the number is prime:" << std::endl;
	std::cin  >> num;

	if (is_prime(num))
		std::cout << num << " is prime!" << std::endl;
	else
		std::cout << num << " is compose!" << std::endl;

	// task 7 function usage
	std::cout << "-----------Task 7-----------" << std::endl;
	unsigned int dividend, divisor;

	std::cout << "Enter dividend and divisor, then you will see how \n"
		"many times the divisor divides the dividend without remainder:" << std::endl;
	std::cin  >> dividend >> divisor;
	std::cout << "divs(" << dividend << ", " << divisor
              << ") = " << divs(dividend, divisor) << std::endl;

	// task 8 function usage
	std::cout << "-----------Task 8-----------" << std::endl;
	double rad;
	std::cout << "Enter radius, then you will see the area of circle with this radius:" << std::endl;
	std::cin  >> rad;
	std::cout << "Circle area: " << std::fixed
		      << std::setprecision(2) << circle_area(rad) << std::endl;

	// task 9 function usage
    std::cout << "-----------Task 9-----------" << std::endl;
	std::cout << "Enter a number N, then another N numbers, "
		"after that you will see the max one:" << std::endl;
	read_inputs();

	return 0;
}
