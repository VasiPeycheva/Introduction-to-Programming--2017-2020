#include <iostream>

int main()
{
	unsigned int day;

	std::cin >> day;

	switch (day)
	{
	case 1:std::cout << "Monday\n"; break;
	case 2:std::cout << "Tuesday\n"; break;
	case 3:std::cout << "Wednesday\n"; break;
	case 4:std::cout << "Thursday\n"; break;
	case 5:std::cout << "Friday\n"; break;
	case 6:std::cout << "Saturday'n"; break;
	case 7:std::cout << "Sunday\n"; break;
	default: std::cout << "Not day of the week! \n";
		break;
	}

	return 0;
}