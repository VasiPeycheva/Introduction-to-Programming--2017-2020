#include<iostream>

typedef bool(*fptrCompare)(int, int);

void printArr(int* pArr, size_t size) {

	for (size_t i = 0; i < size; i++)
		std::cout << pArr[i] << ' ';

	std::cout << '\n';

}

bool greater(int x, int y) {

	return x > y;
}

bool less(int x, int y) {

	return x < y;
}

//the third argument is the function
//which we will be using to compare the array's elements
void selectionSort(int *arr, size_t size, fptrCompare cmp) {

	size_t index;

	for (size_t i = 0; i < size - 1; i++) {

		index = i;

		for (size_t j = i + 1; j < size; j++)
			if (cmp(arr[index], arr[j])) //the slight difference is here
				index = j;

		std::swap(arr[i], arr[index]);
	}

}

int main() {

	int givenArr[] = { 1, 15, 23, 11, -125, 45, -9, 911 };
	
	size_t size = sizeof(givenArr) / sizeof(int);

	std::cout << "given array : \n";
	printArr(givenArr, size);

	selectionSort(givenArr, size, less);
	std::cout << "\nafter sorting with less :\n";
	printArr(givenArr, size);

	selectionSort(givenArr, size, greater);
	std::cout << "\nafter sorting with greater :\n";
	printArr(givenArr, size);

	return 0;
}
