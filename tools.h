#ifndef _TOOLS_H
#define _TOOLS_H

#define SUDOKUSIZE 9

void get_data(char* file, int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE]);

void print_line(int* line);

void output_matrix(int matrix[][SUDOKUSIZE]);
#endif
