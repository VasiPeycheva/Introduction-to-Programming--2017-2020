#include <iostream>
using namespace std;

const int MAX = 16;

// fill the crossword puzzle with words
void fill(char cross[][MAX], int size)
{
	for (size_t i = 0; i < size - 1 ; i++)
	{
		cin >> cross[i];
	}
}

void print(char cross[][MAX], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << cross[i][j];
		}
		cout << '\n';
	}
}

// check if given row and column are filled with the same elements
bool checkWord(char cross[][MAX], int size, int row, int col)
{
	for (size_t i = 0; i < size -1; i++)
	{
		if (cross[row][i] != cross[i][col])
			return false;
	}

	return true;
}

// check how many rows and columns match
int checkCross(char cross[][MAX], int size)
{
	int result = 0;
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (checkWord(cross, size, i, j))
				result++;
		}
	}

	return result;
}

int main()
{
	char cross[MAX][MAX];
	int size;
	cin >> size;
	fill(cross, size);

	cout << "\nThe cross looks: \n";
	print(cross, size);
	cout << "\nYou have: " << checkCross(cross, size) << " matching words! \n";

	return 0;
}