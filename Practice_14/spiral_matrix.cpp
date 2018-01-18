#include<iostream>
#include<iomanip> //setw


const size_t MAXN = 100;
const size_t NUM_TESTS = 10;

//the focus it not on dynamic memory, so ..
unsigned int matrix[MAXN][MAXN] = { 0 };

void printMatrix(size_t k) {

	for (size_t i = 0; i < k; i++) {
		for (size_t j = 0; j < k; j++)
			std::cout << std::setw(3)
				<< matrix[i][j];

		std::cout << std::endl;
	}

	std::cout << std::endl
		<< std::endl
		<< std::endl
		<< std::endl;
}

void fillMatrix(const size_t k, size_t it, size_t curSize) {

	//only one cell to go
	if (it == k * k) {

		matrix[k / 2][k / 2] = it;
		return;
	}

	//begin index
	size_t startCell = (k - curSize) / 2;
	//end index
	size_t border = startCell + curSize - 1;

	//down fill
	for (size_t i = 0; i < curSize; i++)
		matrix[startCell + i][startCell] = it++;

	//left fill ->
	for (size_t i = 1; i < curSize; i++)
		matrix[border][startCell+ i] = it++;

	//up fill
	for (size_t i = border - 1; i > startCell; i--)
		matrix[i][border] = it++;

	//right fill <-
	for (size_t i = border; i > startCell; i--)
		matrix[startCell][i] = it++;

	
	if(it <= k * k)
		fillMatrix(k, it, curSize - 2);

}


int main() {

	unsigned int k = 1;

	while (k <= NUM_TESTS) {

		fillMatrix(k, 1, k);

		printMatrix(k);

		k++;
	}

	return 0;
}

