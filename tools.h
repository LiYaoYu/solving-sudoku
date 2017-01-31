#ifndef _TOOLS_H
#define _TOOLS_H

#include "method.h"

void init_suref(suref* element, char c);

void get_data(char* file, suref matrix[][SUDOKUSIZE]);

void print_line(suref line[]);

void output_matrix(suref matrix[][SUDOKUSIZE]);
#endif
