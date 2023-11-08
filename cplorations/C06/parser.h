/****************************************
 * C-ploration 6 for CS 271
 *
 * [NAME] Kevin Walsh
 * [TERM] Fall 2023
 *
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH - 2

typedef int16_t hack_adder;
typedef int16_t opcode;
/** function prototypes **/
char *strip(char *s);

char *extract_label(const char *line, char *label);

void parse(FILE *file);

bool is_Atype(const char *);

bool is_label(const char *);

bool is_Ctype(const char *);

enum instruction_type
{
    Invalid_insruction,
    AType_instruction,
    CType_instruction,
    LType_instruction
};

typedef struct C_instruction
{
    opcode a : 1;
    opcode comp : 2;
    opcode dest : 8;
    opcode jump : 11;

} C_instruction;

typedef struct A_instruction
{
    union
    {
        hack_adder address : 15;
        char *label;
    };
    bool is_addr;

} A_instruction;

struct instruction
{
    union
    {
        A_instruction a_instruction;
        C_instruction c_instruunion;
    };
    enum instruction_type type;

    
};
