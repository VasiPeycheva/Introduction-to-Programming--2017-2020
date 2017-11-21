#include<iostream> //std::cin , std::cout
#include<cstdlib> //srand , rand
#include<ctime> //time

const int MAXN = 1024; // max number of elements we can store

//task1
//reading array elements from console input
void fillArray(int arr[], size_t size) {

	//iterating through array's elements
	for (size_t i = 0; i < size; i++) {
	
		//reading each element's value
		std::cout << "enter value for element on index " << i << ": ";
		std::cin >> arr[i];
		std::cout << std::endl;
	}
}

//task1
//printing array elements to console output
void printArray(int arr[], size_t size) {

	//iterating through array's elements
	for (size_t i = 0; i < size; i++) {

		//printing each element's value
		std::cout << "array [" << i << "]= "
				  << arr[i] << std::endl;
	}
}


//task2
//fills the array with random values in [-300;300]
const unsigned int INTERVAL_SIZE = 601;
void init(int arr[], size_t size) {
	
	//iterating through array's elements
	for (size_t i = 0; i < size; i++) {

		//setting each element's value to a random one
		arr[i] = rand() % INTERVAL_SIZE; // [0, 600]

		if (arr[i] < INTERVAL_SIZE / 2)
			arr[i] = (-1) * arr[i];    //[-300, 300]
		else
			arr[i] -= INTERVAL_SIZE / 2;

		/*another approach : 
		arr[i] = rand() % 301;

		arr[i] = ((rand() % 2) ? arr[i] : -arr[i] ) ;
		*/
	}

}


//task3a
//finds the sum of all elements in an array
long long int sumElems(int arr[], size_t size) {

	long long int sum = 0;

	for (size_t i = 0; i < size; i++)
		sum += arr[i];

	return sum;

}

//task3b
//finds the product of all elements in an array
long long int productElems(int arr[], size_t size) {

	long long int pr = 1;

	for (size_t i = 0; i < size; i++)
		pr *= arr[i];

	return pr;

}

//task4a
//finds the minimal element, returns its index
size_t minArray(int arr[], size_t size) {

	size_t minIndex = 0; //the index of the minimal elem
						//in the beginning we assume that the first elem
						//is the smallest one

	for (size_t i = 1; i < size; i++)
		if (arr[minIndex] > arr[i]) //checks if we should update the min elem's index
			minIndex = i;

	return minIndex;

}

//task4b
//finds the maximal element, returns its index
size_t maxArray(int arr[], size_t size) {

	size_t maxIndex = 0; //the index of the maximal elem
						 //in the beginning we assume that the first elem
						 //is the largest one

	for (size_t i = 1; i < size; i++)
		if (arr[maxIndex] < arr[i]) //checks if we should update the max elem's index
			maxIndex = i;

	return maxIndex;

}

//task5
//helper function checks if a given number is a prime or not
bool isPrime(int n) {

	n = (n > 0) ? n : -n; //abs(n)

	for (int i = 2; i*i < n; i++)  // we don't have to use sqrt
		if (n % i == 0)			   //we can if check  i * i is less than n 
			return false;
	
	return true;
}

//prints all prime elements 
void printPrimesArray(int arr[], size_t size) {

	for (size_t i = 0; i < size; i++)
		if (isPrime(arr[i])) //checks if we should print the current number
			std::cout << arr[i] << ' ';

}

//task6
//returns the product of indexes of all odd elements
long long int productIndexOddElems(int arr[], size_t size) {

	long long int pr = 1;

	for (size_t i = 0; i < size; i++)
		if (arr[i] & 1) //checks if the number is odd 
			pr *= i; //multiplies the product by the current index -> i

	return pr;
}

//task7
//returns the difference between (P) product of elements on even indexes 
// and (S) sum of elements on odd indexes / P - S = ?
long long int diffElems(int arr[], size_t size) {

	long long int prEven = 1;
	long long  int sumOdd = 0;

	for (size_t i = 0; i < size; i++)
		if (i % 2 == 0)
			prEven *= arr[i];
		else
			sumOdd += arr[i];

	return prEven - sumOdd;

}

//task8
//helper function checks if a number has more up bits (1) or down bits (0)
//in its binary representation
//without checking the sign bit (which is the MSB)
bool hasMoreUpBits(int n) {

	unsigned short ones = 0;

	int mask = 1;

	for (int i = 0; i < sizeof(int) * 8 - 2; i++)
		if (n & (mask << i))
			ones++;

	//ones > 15
	return ones > (sizeof(int) * 8 - 1) / 2;

}

//returns the sum of all elements with more ones in their binary representation
long long int sumUpBitsElems(int arr[], size_t size) {

	long long int sum = 0;

	for (size_t i = 0; i < size; i++)
		if (hasMoreUpBits(arr[i]))
			sum += arr[i];
			
	return sum;

}



int main() {

	int arr[MAXN]; // allocating the memory

	size_t size; //logical size, we will use 
	  		     //only a part of our allocated memory
				 // !!! size_t is a typedef for unsigned int !!!

	do {

		std::cout << "enter a number for array size less than 1024\n";
		std::cin >> size;
	} while (size >= 1024);


	fillArray(arr, size);
	
	std::cout << "\nthe array content is :\n";
	printArray(arr, size);

	srand(time(NULL)); // seeding the random generator with
					  //starting value - the current time
					  //we need to do this only once in our program
	std::cout << "\nnow lets fill it with random values\n";
	init(arr, size);

	std::cout << "\nthe array content is :\n";
	printArray(arr, size);

	std::cout << "\nsum of all elements :\n";
	std::cout << sumElems(arr, size) << std::endl;

	std::cout << "\nproduct of all elements :\n";
	std::cout << productElems(arr, size) << std::endl;

	size_t minIndex = minArray(arr, size);
	std::cout << "\nthe smallest element is on index "
		<< minIndex << " and it's value is : " << arr[minIndex] << std::endl;

	size_t maxIndex = maxArray(arr, size);
	std::cout << "\nthe largest element is on index "
		<< maxIndex << " and it's value is : " << arr[maxIndex] << std::endl;

	std::cout << "\nall prime elements are : \n";
	printPrimesArray(arr, size);

	std::cout << "\nproduct of indexes of all odd elements : "
		<< productIndexOddElems(arr, size) << std::endl;


	std::cout << "\ndifference between(P) product of elements on even indexes"
		" and (S) sum of elements on odd indexes / P - S = "
		<< diffElems(arr, size) << std::endl;


	std::cout << "\nthe sum of all elements with more ones"
		" in their binary representation is : "
		<< sumUpBitsElems(arr, size);

	return 0;
}