#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

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
		fseek(fptr, 1, SEEK_CUR); //jump return char '\n'
	}
}

void print_line(int* line)
{
	printf("| ");
	int i;
	for (i = 0; i < SUDOKUSIZE; i++) {
		printf("%d ", line[i]);
		if ((i % 3) == 2)
			printf("| ");
	}
	puts("");
}

void output_matrix(int matrix[][SUDOKUSIZE])
{
	puts("+-------+-------+-------+");
	int i;
	for (i = 0; i < SUDOKUSIZE; i++) {
		print_line(matrix[i]);
		if ((i % 3) == 2)
			puts("+-------+-------+-------+");
	}
}
