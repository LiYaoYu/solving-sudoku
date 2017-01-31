#include <stdio.h>

#include "tools.h"
#include "method.h"

int main()
{
	get_data();

	//print origin sudoku
	output_matrix();

	//algorithm
	fill_obv(); //fill in the obvious field
	fill_remain(); //fill in the remain field

	//print result sudoku
	output_matrix();
}
