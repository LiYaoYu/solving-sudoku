#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "method.h"

void init_surinfo(surinfo* element, char c)
{
	(*element).value = c;
	if (c == 0) {
		(*element).origin = 0;
		memset((*element).ref, 1, sizeof((*element).ref));
	} else {
		(*element).origin = 1;
		memset((*element).ref, 0, sizeof((*element).ref));
	}
}

void get_data()
{
	extern surinfo matrix[SUDOKUSIZE + 1][SUDOKUSIZE + 1];

	char file[MAXFILENAME];
	FILE* fptr = NULL;

	while (!fptr) {
		puts("Please input the sudoku data file name.");
		scanf("%s", file);

		fptr = fopen(file, "r");
		if (!fptr)
			puts("File is not exist.");
	}

	int i;
	int j;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		for (j = 1; j < SUDOKUSIZE + 1; j++) {
			init_surinfo(&matrix[i][j], (fgetc(fptr) - '0'));
		}
		fseek(fptr, 1, SEEK_CUR); //jump return char '\n'
	}
}

void print_line(surinfo line[])
{
	printf("| ");
	int i;
	int v;
	int o;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		v = line[i].value;
		o = line[i].origin;
		if (v && o) //value is not zero
			printf("%d ", v);
		else if (v && !o)
			printf("\x1b[33m%d\x1b[0m ", v);
		else //value is equal to zero
			printf("  ");

		if ((i % 3) == 0)
			printf("| ");
	}
	puts("");
}

void output_matrix()
{
	extern surinfo matrix[SUDOKUSIZE + 1][SUDOKUSIZE + 1];

	puts("+-------+-------+-------+");
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		print_line(matrix[i]);
		if ((i % 3) == 0)
			puts("+-------+-------+-------+");
	}
}
