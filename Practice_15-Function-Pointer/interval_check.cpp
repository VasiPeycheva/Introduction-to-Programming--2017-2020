#include<iostream>

typedef int(*fptrMathFunc)(int);

int id(int x) {

	return x;
}

int square(int x) {

	return x * x;
}

bool checkInterval(int beg, int end, fptrMathFunc mf) {

	for (int i = beg; i <= end - 1; i++)
		for (int j = i + 1; j <= end; j++)
			if (mf(i) == mf(j))
				return true;

	return false;

}

int main() {


	std::cout << "checking id(x) in the interval [-10; 10] :\n";
	std::cout << (checkInterval(-10, 10, id) ?
		"there are two points with the same function value\n" :
		"there aren't such points\n");


	std::cout << "\nchecking square(x) in the interval [-10; 10] :\n";
	std::cout << (checkInterval(-10, 10, square) ?
		"there are two points with the same function value\n" :
		"there aren't such points\n");

	return 0;
}
