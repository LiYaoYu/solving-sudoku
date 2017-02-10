#include <stdio.h>

#include "tools.h"
#include "method.h"

int main()
{
	get_data();

	//print origin sudoku
	output_matrix();

	//algorithm
	//TODO: check if there is a answer database
	//TODO: find relative answers.

	//print result sudoku
	output_matrix();
}
