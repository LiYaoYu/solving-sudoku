#ifndef _METHOD_H
#define _METHOD_H

#define SUDOKUSIZE 9

typedef struct {
	int value;
	int origin;
	int ref[SUDOKUSIZE + 1];
}surinfo; //sudoku reference

int cnt_valid();

void update_ref(int row, int col);

void check_ref(int row, int col);

void handle_row(int row, void (*pfunc)(int, int));

void handle_col(int col, void (*pfunc)(int, int));

void handle_blo(int blo, void (*pfunc)(int, int));

void handle_ref();

void handle_value();

void fill_obv();

void fill_remain();

#endif
