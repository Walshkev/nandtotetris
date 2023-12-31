/****************************************
 * C-ploration 7 for CS 271
 *
 * [NAME] $Kevin WalshE$
 * [TERM] FALL $2023$
 *
 ****************************************/
#include "parser.h"
#include "symtable.h"
#include "error.h"

/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */

char *strip(char *s)
{
	char *s_new = malloc(strlen(s) + 1);
	// char s_new[MAX_LINE_LENGTH];

	int i = 0;
	for (char *s2 = s; *s2; s2++)
	{
		if (*s2 == '/')
		{
			if (*(s2 + 1) == '/')
			{
				break;
			}
		}
		else if (!isspace(*s2))
		{

			s_new[i++] = *s2;
		}
	}
	s_new[i] = '\0';

	strcpy(s, s_new);

	return s;
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments.
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE *file)
{

	// your code here
	char line[MAX_LINE_LENGTH] = {0};
	char label[MAX_LABEL_LENGTH] = {0};
	int line_num = 0 ; 
	int instr_num =0 ; 

	char inst_type; // unsigned int line_num = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_num = line_num+1 ; 
		if( line_num>MAX_INSTRUCTIONS){
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}
		strip(line);
		
		if (*line == '\0')
		{
			continue;
		}

		// cheack to see if it is a type c type and

		if (is_Atype(line))
		{
			
			
			inst_type = 'A';
			
		}
		else if (is_label(line))
		{
			inst_type = 'L';
			
			extract_label(line,label);
			
			if( !isalpha(*label)){
				exit_program(EXIT_INVALID_LABEL, line_num, label);
			}
			else if (symtable_find(label) != NULL)
				{
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, label);
				}
				strcpy(line, label);
				symtable_insert(label,instr_num);
			
				continue;
			
			}
		else if (is_Ctype(line))
		{
		
			
			inst_type ='C';
		}

		// printf("%c  ", inst_type);
		// printf("%s\n", line);
		
		printf("%u: %c  %s\n", instr_num, inst_type, line);
		instr_num++;
	}

}

bool is_Atype(const char *s)
{
	if (s[0] == '@')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_label(const char *s)
{
	if (s[0] == '(' && s[strlen(s) - 1] == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_Ctype(const char *s)
{

	if (!is_Atype(s) && !is_label(s))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char *extract_label(const char *line, char *label)
{

	int i = 0;
	for (const char *s2 = line; *s2; s2++)
		if (*s2 == '(' || *s2 == ')')
		{
			continue;
		}
		else
		{
			label[i] = *s2;
			i++;
		}

	

	return label;
}
