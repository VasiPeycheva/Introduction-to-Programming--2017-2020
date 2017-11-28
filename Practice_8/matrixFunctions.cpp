#include <iostream> // std::cin , std::cout

//with these lines we can say that
//we are going to use the names 'cin' and 'cout'
//form the 'std' namespace
//it will help us to avoid writing 'std::'
//in front of cin and cout
//but also will avoid including all names 
//from the std namespace
using std::cin;
using std::cout;

//constants for maximum dimensions of the matrix
const int MAX_ROWS = 16;
const int MAX_COLS = 16;

//task 1a
//Fill the matrix from standard input(keyboard)
void fillMatrix(int mat[][MAX_COLS], size_t m, size_t n)
{
	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			cin >> mat[row][col];
		}
	}
}

//task 1b
//Print the matrix to standard output(console)
void printMatrix(int mat[][MAX_COLS], size_t m, size_t n)
{
	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			cout << mat[row][col] << ' ';
		}
		cout << '\n';
	}
}

//task 2
//Find minimum element in the matrix
int minMatrixElement(int mat[][MAX_COLS], size_t m, size_t n)
{
	//set the first element as default
	int minElement = mat[0][0];

	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			if (minElement > mat[row][col]) //if we find smaller than current minimum
				minElement = mat[row][col]; //take it's value
		}
	}
	return minElement; //return the value of the minimum
}

//task 3
//Multiply every element by scalar
void multiplyWithScalar(int mat[][MAX_COLS], size_t m, size_t n, int scalar)
{
	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			mat[row][col] *= scalar;
		}
	}
}

//task 4
//Sum of two matrices with same size
void sumMatrices(int M[MAX_ROWS][MAX_COLS], int T[MAX_ROWS][MAX_COLS],
						   size_t m, size_t n)
{
	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			M[row][col] += T[row][col];
		}
	}
}

//task 5
//Print the frame of matrix
//FirstSolution
void printFrame(int mat[][MAX_COLS], size_t m, size_t n)
{
	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			if ((row == 0 || row == m - 1) || (col == 0 || col == n - 1))
				cout << mat[row][col] << ' ';
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

//Second solution
void printFrame2(int mat[][MAX_COLS], size_t m, size_t n)
{
	//print first row
	for (size_t col = 0; col < n; col++)
		std::cout << mat[0][col] << ' ';

	std::cout << '\n';
	//print next n-2
	for (size_t row = 1; row < m - 1; row++)
	{
		std::cout << mat[row][0] << ' ';
		for (size_t col = 1; col < n - 1; col++)
			std::cout << "  ";

		std::cout << mat[row][n - 1] << ' ';
		std::cout << '\n';
	}

	//print last row
	for (size_t col = 0; col < n; col++)
		std::cout << mat[m - 1][col] << ' ';
	std::cout << '\n';
}


//task 6
//Print Diagonals of square matrix
//It won't work if it is not square
void printDiagonals(int mat[][MAX_COLS], size_t n)
{
	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			if (row == col || row + col == n - 1)
				cout << mat[row][col] << ' ';
			else
				cout << "  ";
		}
		cout << '\n';
	}
}


//task 7 
//the function finds the wanted result 
//and then directly prints it to the standard output
void belowAndAboveTheDiagonal(int mat[][MAX_COLS], size_t rows, size_t cols) {

	int sumAbove = 0;
	int cntOddBelow = 0;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++) {

			//above the main diagonal
			if (i < j)
				sumAbove += mat[i][j];

			//not else !!! because if we have else it will be i <= j 
			//which will contain the main diagonal
			//below the main diagonal
			if ((i > j) && (mat[i][j] % 2 != 0)) // and the element is odd
				cntOddBelow++;
		}

	std::cout << sumAbove * cntOddBelow;
}

//task8
//simple function that checks if the 'elem' is
//the smallest elem in a given array 'arr' with size 'size'
bool isMaxInRow(int elem, int arr[], size_t size) {

	for (size_t i = 0; i < size; i++)
		if (arr[i] > elem)
			return false;

	return true;
}

//a function that prints the saddle element of a given matrix
//not the smartest solution 
//the function checks each point of the matrix
//but there is a better algorithm : http://www.geeksforgeeks.org/saddle-point-matrix/
void saddlePoint(int mat[][MAX_ROWS], size_t rows, size_t cols)
{

	int maxElRow, minElCol;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (isMaxInRow(mat[i][j], mat[i], cols)) { //we can pass the whole row
								   //as a function argument
				 //checking the column here,
				 //because we can't pass it to a function

				bool isMinInCol = true;

				for (size_t k = 0; k < rows && isMinInCol; k++)
					if (mat[k][j] < mat[i][j])
						isMinInCol = false;

				//we have found the saddle point
				if (isMinInCol) {

					std::cout << "the saddle point is : matrix("
						<< i << ", " << j << ")=" << mat[i][j] << '\n';
					return; // there can be only one saddle point

				}
			}

	//if we reach here there isn't a saddle point
	std::cout << "there isn't a saddle point in the given matrix!!!\n\n";
}


int main()
{
	unsigned int m, n;
	int scalar;
	std::cout << "Enter number of rows: ";
	cin >> m;
	std::cout << "Enter number of columns: ";
	cin >> n;

	if (m > MAX_ROWS || n > MAX_COLS) {

		std::cout << "error : can't handle such a big matrix!\n";
		return -1; //here we are exiting our program with error code -1
	}

	int matrix[MAX_ROWS][MAX_COLS]; //allocating enough memory
							  
	fillMatrix(matrix, m, n);    //3x3 //1 2 3
					   //4 5 6
					   //7 8 9

	cout << "-----------------\n";
	printMatrix(matrix, m, n);

	cout << "-----------------\n";

	cout << "Minimal element of the matrix : " << minMatrixElement(matrix, m, n) << '\n';

	cout << "-----------------\n";

	printMatrix(matrix, m, n);

	cout << "-----------------\n";
				     //1 2 3
	printFrame(matrix, m, n);    //4   6
	      			     //7 8 9
	cout << "-----------------\n";
	printFrame2(matrix, m, n);

	cout << "-----------------\n";
	     			     //1   3
	printDiagonals(matrix, n);   //  2
				     //7   9
	cout << "-----------------\n\n";
	cout << "Enter a scalar: ";
	cin >> scalar;

	multiplyWithScalar(matrix, m, n, scalar);
	cout << "Multiply with scalar: " << scalar << '\n';
	printMatrix(matrix, m, n);
	cout << "-----------------\n";

	
	//the function will find the saddle point
	//if such point exists and print it's
	//indexes and value to the standard output
	saddlePoint(matrix, m, n);

	std::cout << "\n\nthe sum of the element above the main diagonal,\nmultiplied by"
		" the count of odd element below the main diagonal is: ";
	belowAndAboveTheDiagonal(matrix, m, n); // only calling the function, it will print the result
	std::cout << "\n\n";



	return 0;
}
