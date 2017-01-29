#ifndef _METHOD_H
#define _METHOD_H

void fill_row(int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE]);

void fill_col(int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE]);

void fill_blo(int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE]);

void fill_obv(int matrix[][SUDOKUSIZE], int valid[][SUDOKUSIZE]);

#endif
