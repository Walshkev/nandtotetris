/****************************************
 * C-ploration 3 for CS 271
 * 
 * [NAME] $Kevin Walsh$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LIMIT 200 


int main(int argc, const char *argv[])
{	
 
// if incorrect number of arguments
if(argc !=2){
printf("Usage: %s [filename]\n", argv[0]);
exit(EXIT_FAILURE);
}

FILE *fin = fopen( argv[1], "r" );
	
if (fin== NULL){
	perror("Unable to open file!");
	exit(EXIT_FAILURE);
}
char *out_file=malloc(sizeof(char) * MAX_LIMIT);

strcpy(out_file,"");
strcat(out_file, ".echo");

FILE *fout = fopen( out_file, "w+");


char line[MAX_LIMIT] = {0};
unsigned int line_num = 0;

while (fgets(line, sizeof(line), fin)){
	
	line_num++; 
	printf("[%04d] ",line_num);
	printf(line);
	fprintf( fout ,line);
}

fclose(fin);
fclose(fout);
	
return 1;

}