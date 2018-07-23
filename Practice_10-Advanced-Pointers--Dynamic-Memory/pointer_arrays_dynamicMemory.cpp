#include <iostream>


//if we only want to read or write into an array's
//cells the parameter we take in functions
//is only int* or int []
//but if we want to redirect the pointer ... read below
void readInputArr(int* pArr, size_t logicSize) { // writing to the array's cells

	std::cout << "please enter " << logicSize << " elements\n";

	for (size_t i = 0; i < logicSize; i++)
		std::cin >> pArr[i];

}

//the param const int* pArr means :
//the function will not change the values of the pointed elements
void printArr(const int* pArr, size_t logicSize) {

	std::cout << "\nthe size is : " << logicSize
		<< " the buffer starts at : 0x" << pArr
		<< "\nand the elements are : \n{ ";

	for (size_t i = 0; i < logicSize -1 ; i++)
		std::cout << pArr[i] << ", ";

	std::cout << pArr[logicSize - 1]; //there is not a ',' after the last elem
	std::cout << " }\n";

}

//adding new element at the end of a given array
//considering that the array if full, a memory
//reallocation is needed

//returns true if the new element is successfully added, false else
bool pushBack(int*& pArr, size_t& logicSize, int newElem) {

	//take a look at the parameters...
	//logicSize is taken by ref in order to change the
	//outer world's variable value, if it changes in the function

	//the pointer 'pArr' is a new name for an existing
	//pointer to integers, we should take the pointer by ref
	//because we are going to redirect this pointer to a new memory
	//and if we don't take it by ref a copy of it will be crated and only
	//the copied pointer will be redirected, not the wanted one form the main function
	//try to remove the '&' and see what will happen

	int* oldMem = pArr; //oldMem will point to the old block, which
						//we are going to release after copying each elem from it


	pArr = new (std::nothrow) int[logicSize + 1]; // new space for all old elements + the new one

	//can't allocate memory
	if (pArr == nullptr) {

		pArr = oldMem; // returning to the situation
					   //before the function was called
		
		return false;
	}


	//copying the elements from the old memory to the new one
	for (size_t i = 0; i < logicSize; i++)
		pArr[i] = oldMem[i];

	pArr[logicSize++] = newElem; // adding the new elem on position
								//pArr[logicSize] and then increasing the 
								//logicSize by one

	//we don't need the old memory anymore
	delete[] oldMem;

	//the function ends successfully
	return true;

}

//adding a new element into a full array
//on a wanted index 
bool insertAt(int*& pArr, size_t& logicSize, int newElem, size_t pos) {

	//if the wanted index is outside our array
	//then the operation is just push back
	if (pos >= logicSize)
		return pushBack(pArr, logicSize, newElem);


	int* oldMem = pArr;

	pArr = new (std::nothrow) int[logicSize + 1];

	if (!pArr) { //same as pArr == NULL

		pArr = oldMem; 
		return false;
	}

	size_t i; // taking the var outside to used it into both loops

	//copying elements before the inserted one
	for (i = 0; i < pos; i++)
		pArr[i] = oldMem[i];

	//now i == pos
	pArr[i] = newElem;

	for (; i < logicSize; i++)
		pArr[i + 1] = oldMem[i]; // pArr[i + 1] because of the
								//inserted elem

	logicSize++;

	delete[] oldMem;

	return true;
}



int main() {

	size_t lsize;

	std::cout << "how many elements at the beginning : ";
	std::cin >> lsize;

	//allocating the array with wanted size
	int* pArr = new (std::nothrow) int[lsize];

	//std::nothrow is used to avoid the exception based
	//error handling in C++ and the operator new will
	//return nullptr if the memory allocation is not successful

	if (pArr == nullptr) {

		std::cout << "not enough memory\n";
		return -1; //a value that indicates the outsize world
					//that our program has failed somehow
	}

	readInputArr(pArr, lsize);

	printArr(pArr, lsize);

	if (pushBack(pArr, lsize, 11)) { // trying to push back

		std::cout << "\nsuccessfully pushed back!\n";
		printArr(pArr, lsize);
	}
	else
		std::cout << "\nunsuccessful pushing back!\n";


	if (insertAt(pArr, lsize, 23, 0)) { // trying to 23 at index 0

		std::cout << "\nsuccessfully inserted the new elem !\n";
		printArr(pArr, lsize);
	}
	else
		std::cout << "\nunsuccessful inserting!\n";

	delete[] pArr;


	return 0;
}