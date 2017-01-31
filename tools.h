#ifndef _TOOLS_H
#define _TOOLS_H

#include "method.h"

#define MAXFILENAME 32

void init_surinfo(surinfo* element, char c);

void get_data();

void print_line(surinfo line[]);

void output_matrix();
#endif
