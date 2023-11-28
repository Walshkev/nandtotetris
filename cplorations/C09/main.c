/****************************************
 * C-ploration 7 for CS 271
 *
 * [NAME] $Kevin walsh$
 * [TERM] FALL $2023$
 *
 ****************************************/
#include "parser.h"
// #include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

int main(int argc, const char *argv[])
{

	if (argc != 2)
	{
		exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);
	}
	FILE *fin = fopen(argv[1], "r");

	if (fin == NULL)
	{
		exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
	}
	parse(fin);
	// symtable_print_labels();
	fclose(fin);
	return 0;
}