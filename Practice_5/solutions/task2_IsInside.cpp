#include<iostream>
#include<math.h> // sqrt

//some info given by the task

// "int const" is exactly the same as "const int" 
int const RectX1 = -3;
const int RectY1 = 2;
const int RectX2 = 2;
const int RectY2 = -3;

const int CircleCenterX = 1;
const int CircleCenterY = 1;
const double CircleRadius = 3.0;

const double MushroomRadius = 5.0;
const int MushroomRectX1 = -4;
const int MushroomRectX2 = 4;
const int MushroomRectY = -2;


int main() {


	int x,y;

	std::cin >> x >> y;
	
	std::cout << "the point with coordinates : " 
			  << x << ' ' << y << " \n";

	//checking if the point is in the rectangle given by the task
	//
	//our point's x should be between the rectangle's x-coordinates
	//and same logic about the y coordinate
	if ((x >= RectX1) && (x <= RectX2) && //checks x 
		(y <= RectY1) && (y >= RectY2) ){ //and checks y

		std::cout << "is inside the given rectangle!\n";
	}
	else{

		std::cout << "is NOT inside the given rectangle!\n";
	}

	
	//checking if the point is int the given circle
	//we should check if the distance between our point 
	//and the center of the circle is less the circle's radius

	double distPntToCenter = sqrt((CircleCenterX - x) * (CircleCenterX - x) +
								  (CircleCenterY - y) * (CircleCenterY - y));

	//we are losing some precision here,but
	//we will discuss it later trough the semester
	if (distPntToCenter <= CircleRadius)
		std::cout << "and is in the given circle! \n";
	else
		std::cout << "and is outside the given circle!\n";

	//mushroom part :
	//if y > 0 we should check the first and the second part
	//of the coordinate system (where the semi - circle is)
	//else -> third and fourth (where the semi - rect is)

	bool isInsideMushroom = false;

	if (y > 0) {

		//the center is (0,0), so the math is much more easier
		distPntToCenter = sqrt((x * x) + (y * y));

		if (distPntToCenter <= MushroomRadius)
			isInsideMushroom = true;

	}
	else {

		if ((x >= MushroomRectX1) &&
			(x <= MushroomRectX2) &&
			(y >= -2))
			isInsideMushroom = true;
	}

	if (isInsideMushroom)
		std::cout << "and the point is inside the mushroom!\n";
	else
		std::cout << "and the point is outside the mushroom!\n";

	return 0;
}