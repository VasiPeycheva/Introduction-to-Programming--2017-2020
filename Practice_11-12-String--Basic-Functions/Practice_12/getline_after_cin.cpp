#include<iostream>


int main() {

	int x;
	char buff[32];

	std::cout << "Enter x : ";
	std::cin >> x;

	//try to comment these lines and 
	//see what is happening   <---- form here
	char c = std::cin.get();

	if (c != '\n')
		std::cin.putback(c);  // or cin.unget();
	
	//<--- up to here

	std::cout << "Enter text: ";
	std::cin.getline(buff, 32);


	std::cout << "x = " << x << '\n';
	std::cout << "text is : " << buff;

	return 0;
}