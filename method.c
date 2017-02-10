#include <stdio.h>
#include <strings.h>
#include <math.h>

#include "method.h"

surinfo matrix[SUDOKUSIZE + 1][SUDOKUSIZE + 1]; //sudoku reference matrix
//int simple[2];
//int existed[SUDOKUSIZE + 1] = {0};
/*
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

int update_ref(int row, int col)
{
	int i;
	for (i = 1; i < (SUDOKUSIZE + 1); i++) {
		if (existed[i] && matrix[row][col].ref[i]) {
			matrix[row][col].ref[i] = 0;
			matrix[row][col].remain--;
		}
	}
	return UNFINISHED;
}

int check_ref(int row, int col)
{
	//update ref
	if (matrix[row][col].value != 0) {
		existed[matrix[row][col].value] = 1;
	}
	return UNFINISHED;
}

int update_value(int row, int col)
{
	surinfo element;
	element = matrix[row][col];

	if (element.value) {
		bzero(element.ref, sizeof(element.ref));
		matrix[row][col].remain = 0;
			return UNFINISHED;
	}

	int i;
	int r = 0; //record
	for (i = 0; i < SUDOKUSIZE + 1; i++) {
		if (matrix[row][col].ref[i] && r)
			return UNFINISHED;
		if (matrix[row][col].ref[i] && !r)
			r = i;
	}
	matrix[row][col].value = r;
	matrix[row][col].remain = 0;
	return UNFINISHED;
}

int find_simple(int row, int col)
{
	static int min_remain;

	if (matrix[row][col].remain == 0)
		return UNFINISHED;

	if (row == 1 && col == 1) {
		min_remain = 9;
	}

	//get the smallest remain
	if (matrix[row][col].remain < min_remain) {
		min_remain = matrix[row][col].remain;
		simple[0] = row;
		simple[1] = col;
	}

	if (min_remain == 2)
		return FINISHED;

	return UNFINISHED;
}
*/

void handle_row(int row, int (*pfunc)(int, int))
{
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		if (FINISHED == (*pfunc)(row, i))
			break;
	}
}

void handle_col(int col, int (*pfunc)(int, int))
{
	int i;
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		if (FINISHED == (*pfunc)(i, col))
			break;
	}
}

void handle_blo(int blo, int (*pfunc)(int, int))
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
			if (FINISHED == (*pfunc)(i, j))
				break;
		}
	}
}

/*
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
}

void fill_remain()
{
	if (cnt_valid() == (int)pow(SUDOKUSIZE, 2)) //finished sudoku
		return;

	fill_obv();

	int i;
	//find the element which value might be determined most easily
	for (i = 1; i < SUDOKUSIZE + 1; i++) {
		handle_row(i, &find_simple);
	}

	//TODO
	//recursive to fill the remain elements with the position info
}
*/
