#include<iostream>

//can only answer to the question
//is there such elem, not on which index
bool binarySearch_rec(int* arr, size_t size, int elem) {


	if (size == 0 && arr[size] != elem)
		return false;

	size_t mid = size / 2;

	if (arr[mid] == elem)
		return true;

	if (arr[mid] < elem)
		return binarySearch_rec(arr + mid + 1, size - (mid + 1), elem);
	
	if (arr[mid] > elem)
		return binarySearch_rec(arr, mid - 1, elem);


}

int main() {

	int sortedArr[] = { -121, -9, 5, 11, 23, 48, 70 };

	size_t size = sizeof(sortedArr) / sizeof(int);

	if (binarySearch_rec(sortedArr, size, 48))
		std::cout << "it is here\n";
	else
		std::cout << "there isn't such element\n";

	return 0;
}