#include <stdio.h>

#include "tools.h"
#include "method.h"

#define MAXFILENAME 32

int main()
{
	suref matrix[SUDOKUSIZE][SUDOKUSIZE]; //sudoku reference matrix
	char file[MAXFILENAME];

	puts("Please input the sudoku data file.");
	scanf("%s", file);

	get_data(file, matrix);

	//TODO: algorithm
	//fill_obv(matrix); //fill in the obvious field

	output_matrix(matrix);
}
