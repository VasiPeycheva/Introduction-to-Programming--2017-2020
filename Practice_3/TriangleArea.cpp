#include <iostream>
#include <math.h>

int main()
{
	//	Given:			
	//	Side and height
	unsigned short side, height;
	std::cout << "Input side: ";
	std::cin >> side;
	std::cout << "Input height: ";
	std::cin >> height;
	float area = (side*height) / 2.0;
	std::cout << area << '\n';

	//Given: 3 Sides
	//We use numbers, which can represent triangle sides
	unsigned short a, b, c;
	std::cout << "Input sides: ";
	std::cin >> a >> b >> c;
	float semiPerimeter = (a + b + c) / 2.0;
	float area2 = std::sqrt(semiPerimeter*(semiPerimeter - a)*(semiPerimeter - b)*(semiPerimeter - c));
	std::cout << area2 << '\n';

	return 0;
}