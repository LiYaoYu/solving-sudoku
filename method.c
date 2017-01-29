#include <stdio.h>
#include <stdlib.h>

#include "method.h"

void get_data(char* file, int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE])
{
	FILE* fptr;
	fptr = fopen(file, "r");

	int i;
	int j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			matrix[i][j] = fgetc(fptr) - '0';
			valid[i][j] = matrix[i][j]? 1 : 0;
		}
	}
}
