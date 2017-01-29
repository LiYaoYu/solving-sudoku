#include <stdio.h>

#include "tools.h"
#include "method.h"

#define MAXFILENAME 32

int main()
{
	int matrix[SUDOKUSIZE][SUDOKUSIZE]; //sudoku matrix
	int valid[SUDOKUSIZE][SUDOKUSIZE];  //check the correspond matrix if it is valid
	char file[MAXFILENAME];

	puts("Please input the sudoku data file.");
	scanf("%s", file);

	get_data(file, matrix, valid);

	//TODO: algorithm
	fill_obv(matrix, valid); //fill in the obvious field

	output_matrix(matrix);
}
