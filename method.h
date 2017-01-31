#ifndef _METHOD_H
#define _METHOD_H

#define SUDOKUSIZE 9

typedef struct {
	int value;
	int ref[10];
}suref; //sudoku reference

void check_row(suref matrix[][SUDOKUSIZE]);

void check_col(suref matrix[][SUDOKUSIZE]);

void check_blo(suref matrix[][SUDOKUSIZE]);

void fill_obv(suref matrix[][SUDOKUSIZE]);

#endif
