#include<iostream>
#include<cmath>

const double EPS = 0.0001;

int main() {


	long double a = 11.30 + 3.14;
	long double b = 11.30;


	a -= 3.14;

	//wrong approach
	if (a == b) {

		std::cout << "a == b\n";

	}

	//proper approach
	//checking how close are a and b
	if (abs(a - b) < EPS) {

		std::cout << "EPS checking for \'a == b\'\n";

	}

	return 0;
}