#include<iostream>

int main() {

	unsigned int a, b, c;

	std::cin >> a >> b >> c;

	if (a > b) {

		if (a > c){

			if (b > c) {
				std::cout << a << " > "
					<< b << " > "
					<< c << '\n';
			} else {
				std::cout << a << " > "
					<< c << " >= "
					<< b << '\n';
			}
		} else{ // a > b && a <= c
				
			std::cout << c << " >= "
				<< a << " > "
				<< b << '\n';
		}
	} else { // a <= b

		if (b > c) {
			
			if (a > c) {
				
				std::cout << b << " >= "
					<< a << " > "
					<< c << '\n';
			} else {
				
				std::cout << b << " > "
					<< c << " >= "
					<< a << '\n';
			}

		} else { // b <= c
			
			std::cout << c << " >= "
				<< b << " >= "
				<< a << '\n';
		}
	}



	return 0;
}
