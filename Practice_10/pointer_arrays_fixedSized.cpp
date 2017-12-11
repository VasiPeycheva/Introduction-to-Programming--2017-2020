#include<iostream>

int const MAXN = 1024;

void swap(int& first, int& second) {

	int temp = first;
	first = second;
	second = temp;

}

//arrays are passed to functions
//by a pointer to their beginning 
//int* arr <=> int arr[] as function arguments
void printArr(int* arr, size_t logicSize) {

	for (size_t i = 0; i < logicSize; i++)
		std::cout << arr[i] << ' ';// <=> *(arr + i) pointers arithmetics

	//with (arr + i ) we jump to the element on address arr + i*sizeof(typeof(arr))
	//which is the address of the wanted element and the 'touch' it
	//we should apply the dereferencing operator *

	std::cout << std::endl;

}

void printArrUgly(int* pArr, size_t logicSize) {

	while (logicSize--){

		std::cout << *pArr << ' '; //prints the pointed value
		pArr++; //moving the pointer to the next element
	}

	std::cout << std::endl;
}

int main() {


	int arr[MAXN] = { 1, 2, 3, 4, 5};
	size_t lsize = 5;

	printArr(arr, lsize);

	//push_back 

	int newElem = 11;

	arr[lsize++] = newElem;

	printArrUgly(arr, lsize);

	//insert_at
	newElem = 23;
	int atIndex = 2;

	//push_back
	arr[lsize++] = newElem;

	//rolling it back...
	int back = lsize - 1;
	while (back > atIndex) {

		swap(arr[back], arr[back - 1]);

		back--;
	}

	printArr(arr, lsize);
	
	//but what will happen if logicSize > MAXN
	//maybe reading pointer_arrays_dynamicMemory
	//will help you ?


	return 0;
}