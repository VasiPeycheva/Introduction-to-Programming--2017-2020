#include<iostream>

int main() {

	unsigned int x, y;

	std::cin >> x >> y;

	if (x <= 1 || y <= 1) {
		std::cout << "can't draw! \n";
		return 0;
	}

	//top line
	for (unsigned int i = 0; i < x; i++)
		std::cout << "* ";
	

	std::cout << '\n';
	
	//the side lines
	for (unsigned int i = 0; i < y - 2; i++) {

		std::cout << "* ";

		for (unsigned int j = 0; j < x - 2; j++) {
			std::cout << "  ";
		}

		std::cout << "*\n";
	}

	//the bottom line
	for (unsigned int i = 0; i < x; i++) {
		std::cout << "* ";
	}

	std::cout << '\n';

	return 0;
}