#include "error.h"
#include <cstdio>





const char *error_messages[] =
{
    [EXIT_INCORRECT_ARGUMENTS] = "Usage: %s [filename]",
    [EXIT_CANNOT_OPEN_FILE] =  "Cannot open file %s" ,
    [EXIT_INVALID_LABEL] = "Line %u: %s : Invalid label name",
    [EXIT_SYMBOL_ALREADY_EXISTS] = "Line %u: %s : Symbol is already defined"
};


void exit_program(enum exitcode code, ...)
{
    va_list arguments;
    va_start(arguments, code);

    printf("ERROR: ");
    vfprintf(stdout, error_messages[code], arguments);
    printf("\n");

    va_end(arguments);
    exit(code);
}