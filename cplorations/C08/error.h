#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdarg.h> 

// All code in file
enum exitcode   
{
/*
 * Error code 1 represents that given file does not exist.
 */
    EXIT_INCORRECT_ARGUMENTS = 1,
    EXIT_CANNOT_OPEN_FILE =2,
    EXIT_INVALID_LABEL =3,
    EXIT_SYMBOL_ALREADY_EXISTS =4 ,

};


void exit_program(enum exitcode code, ...);

#endif