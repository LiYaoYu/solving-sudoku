#include <strings.h>
#include <math.h>

#include "method.h"

surinfo matrix[SUDOKUSIZE + 1][SUDOKUSIZE + 1]; //sudoku reference matrix
int existed[SUDOKUSIZE + 1] = {0};

int cnt_valid()
{
	int i;
	int j;
	int n = 0;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		for (j = 0; j < SUDOKUSIZE + 1; j++) {
			n += (matrix[i][j].value == 0)? 0 : 1;
		}
	}
	return n;
}

void update_ref(int row, int col)
{
	int i;
	for (i = 1; i < (SUDOKUSIZE + 1); i++) {
		if (existed[i] && matrix[row][col].ref[i])
			matrix[row][col].ref[i] = 0;
	}
}

void check_ref(int row, int col)
{
	//update ref
	if (matrix[row][col].value != 0) {
		existed[matrix[row][col].value] = 1;
	}
}

void update_value(int row, int col)
{
	int i;
	int r = 0; //record
	for (i = 0; i < SUDOKUSIZE + 1; i++) {
		if ((matrix[row][col].ref[i] && r) || matrix[row][col].value)
			return;
		if (matrix[row][col].ref[i] && !r)
			r = i;
	}
	matrix[row][col].value = r;
}

void handle_row(int row, void (*pfunc)(int, int))
{
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		(*pfunc)(row, i);
	}
}

void handle_col(int col, void (*pfunc)(int, int))
{
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		(*pfunc)(i, col);
	}
}

void handle_blo(int blo, void (*pfunc)(int, int))
{
/*
 * block:
 * +---+---+---+
 * | 1 | 2 | 3 |
 * +---+---+---+
 * | 4 | 5 | 6 |
 * +---+---+---+
 * | 7 | 8 | 9 |
 * +---+---+---+
 */
	int i, j;
	int row, col;

	//get the block start row and 0.1 here can be any number small than 1
	row = (blo - 0.1) / sqrt(SUDOKUSIZE);
	row *= sqrt(SUDOKUSIZE);
	row += 1;

	//get the block start col
	col = (((blo + (int)sqrt(SUDOKUSIZE) - 1) % 3 * 3) + 1);

	for (i = row; i < row + 3; i++) {
		for (j = col; j < col + 3; j++) {
		(*pfunc)(i, j);
		}
	}
}

void handle_ref()
{
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		bzero(existed, sizeof(existed));
		handle_row(i, &check_ref);
		handle_row(i, &update_ref);

		bzero(existed, sizeof(existed));
		handle_col(i, &check_ref);
		handle_col(i, &update_ref);

		bzero(existed, sizeof(existed));
		handle_blo(i, &check_ref);
		handle_blo(i, &update_ref);
	}
}

void handle_value()
{
	int i;

	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		handle_row(i, &update_value);
	}
}

void fill_obv()
{
	int n_valid;
	n_valid = cnt_valid();

	//check and update the matrix.ref
	handle_ref();

	//fill in the matrix.value
	handle_value();

	if (n_valid != cnt_valid())
		fill_obv();
	
	return;

}

void fill_remain()
{
	//TODO
}
