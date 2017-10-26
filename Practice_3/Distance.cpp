//calculate the distance between two given points
#include <iostream>
#include <math.h>

int main()
{
	int x1, y1;
	int x2, y2;

	std::cout << "Input x,y for point1: ";
	std::cin >> x1 >> y1;
	std::cout << "Input x,y for point1: ";
	std::cin >> x2 >> y2;

	float distance = std::sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	std::cout << "Distance between Point1 and Point2 is: " << distance;

	return 0;
}