#ifndef _METHOD_H
#define _METHOD_H

#define SUDOKUSIZE 9
#define FINISHED 1
#define UNFINISHED 0

typedef struct {
	int value;
	int origin;
	int remain;
	int ref[SUDOKUSIZE + 1];
}surinfo; //sudoku reference

int cnt_valid();

int update_ref(int row, int col);

int  check_ref(int row, int col);

int find_simple(int row, int col);

void handle_row(int row, int (*pfunc)(int, int));

void handle_col(int col, int (*pfunc)(int, int));

void handle_blo(int blo, int (*pfunc)(int, int));

void handle_ref();

void handle_value();

void fill_obv();

void fill_remain();

#endif
