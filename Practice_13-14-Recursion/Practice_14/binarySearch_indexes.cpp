#include<iostream>

int binarySearch_rec(int* arr, size_t left, size_t right, int elem) {


	if (left == right && arr[left] != elem)
		return -1;

	size_t mid = (left + right) / 2;

	if (arr[mid] == elem)
		return mid;

	if (arr[mid] < elem)
		return binarySearch_rec(arr, mid + 1, right, elem);
	
	if (arr[mid] > elem)
		return binarySearch_rec(arr, left, mid - 1, elem);

}


int binarySearch(int* arr, size_t size, int elem) {

	return binarySearch_rec(arr, 0, size, elem);

}

int main() {

	int sortedArr[] = { -121, -9, 5, 11, 23, 48, 70 };

	size_t size = sizeof(sortedArr) / sizeof(int);

	int index = binarySearch(sortedArr, size, -9);

	std::cout <<"found -9 at : " << index 
		<< std::endl; 

	return 0;
}