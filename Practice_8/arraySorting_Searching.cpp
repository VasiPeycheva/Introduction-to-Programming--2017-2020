#include<iostream>

//simply prints array members
void printArr(int arr[], size_t size) {

	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << "\n\n";

}

//searches for 'elem' in given array
//if 'elem' is found, the function returns its index
//if 'elem' isn't a member in the given array
//then the function returns -1
int linearSearch(int arr[], size_t size, int elem) {

	//iterating through the array
	for (size_t i = 0; i < size; i++)
		if (arr[i] == elem) //checks each element
			return i; //if found returns its index

	//not found
	return -1;
}

//TODO : searching using binary search algorithm
//int binarySearch(int arr[], size_t size);

//sorting a array applying 'min' task
//in array with size - 1 each time 
void selectionSort(int arr[], size_t size) {

	int minIndex;

	for (size_t i = 0; i < size - 1; i++) {

		minIndex = i;

		//searching for min elem in the 'smaller' array
		for (size_t j = i + 1; j < size; j++) {

			if (arr[minIndex] > arr[j]) 
				minIndex = j;

		}

		//swap if we have changed the index
		if (minIndex != i) {
			int temp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = temp;
		}

		//for debug reasons
		//in each step first i elems are already sorted. Why?
		//std::cout << "step " << i + 1 << "\n\n";
		//printArr(arr, size);
	}
}


//sorts an array using card player's algorithm
//each time inserts the current element into the sorted half
void insertionSort(int arr[], size_t size) {

	int temp;

	for(size_t i = 1 ; i < size ; i++)
		for (size_t j = i ; j > 0 && arr[j] < arr[j - 1]; j--) {//adding the condition
			//swapping										 // arr[j-1] > arr[j]
			temp = arr[j -1];								 //in the for loop's condition	 
			arr[j-1] = arr[j];								 //is much better			  
			arr[j] = temp;									//than having if statement in the loop 
		}
}


int main() {

	int arr[] = { 9, 15 , 11 , 6, 38, 4 };
	size_t size = 6;

	std::cout << "given array : \n";
	printArr(arr, size);

	selectionSort(arr, size);

	std::cout << "after sorting by Selection sort\n";
	printArr(arr, size);
	std::cout << "\n\n";

	int arr1[] = { 9, 15 , 11 , 6, 38, 4 };


	std::cout << "again given array : \n";
	printArr(arr1, size);

	insertionSort(arr1, size);

	std::cout << "after sorting by Insertion sort\n";
	printArr(arr1, size);
	std::cout << "\n\n";

	int searchedElem = 11;
	std::cout << "searching for elem " << searchedElem
		<<'\n';
	
	int resultIndex = linearSearch(arr1, size, searchedElem);
	if (resultIndex != -1)
		std::cout << "found at index " << resultIndex << '\n';
	else
		std::cout << "no such element in the given array!\n";

	
	return 0;
}