#include <stdio.h>

#include "method.h"

#define MAXFILENAME 32

int main()
{
	int matrix[9][9]; //sudoku matrix
	int valid[9][9];  //check the correspond matrix if it is valid
	char file[MAXFILENAME];

	puts("Please input the sudoku data file.");
	scanf("%s", file);

	get_data(file, matrix, valid);

	//TODO
	puts("after get data");
}
