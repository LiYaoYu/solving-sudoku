#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

void init_suref(suref* element, char c)
{
	(*element).value = c;
	if (c == 0)
		memset((*element).ref, 1, sizeof((*element).ref));
	else 
		memset((*element).ref, 0, sizeof((*element).ref));
}

void get_data(char* file, suref matrix[][SUDOKUSIZE])
{
	FILE* fptr;
	fptr = fopen(file, "r");

	int i;
	int j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			//matrix[i][j].value = fgetc(fptr) - '0';
			init_suref(&matrix[i][j], (fgetc(fptr) - '0'));
		}
		fseek(fptr, 1, SEEK_CUR); //jump return char '\n'
	}
}

void print_line(suref line[])
{
	printf("| ");
	int i;
	for (i = 0; i < SUDOKUSIZE; i++) {
		printf("%d ", line[i].value);
		if ((i % 3) == 2)
			printf("| ");
	}
	puts("");
}

void output_matrix(suref matrix[][SUDOKUSIZE])
{
	puts("+-------+-------+-------+");
	int i;
	for (i = 0; i < SUDOKUSIZE; i++) {
		print_line(matrix[i]);
		if ((i % 3) == 2)
			puts("+-------+-------+-------+");
	}
}
