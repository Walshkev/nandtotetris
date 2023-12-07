/****************************************
 * C-ploration 9 for CS 271
 *
 * [NAME] Kevin Walsh
 * [TERM] Fall 2023
 *
 ****************************************/

#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include "symtable.h"
#include "error.h"
#include "hack.h"



#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH - 2
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS

typedef int16_t hack_adder;
typedef int16_t opcode;
/** function prototypes **/
char *strip(char *s);

char *extract_label(const char *line, char *label);



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
    opcode comp : 7;
    opcode dest : 4;
    opcode jump : 4;

} C_instruction;

typedef struct A_instruction
{
    union
    {
        hack_adder address ;
        char *label;
    }operand;

    bool is_addr;

} A_instruction;

typedef struct instruction
{
    union
    {
        A_instruction a_instruction;
        C_instruction c_instruction;
    } instr;
    enum instruction_type type;

    
}instruction;


void add_predefined_symbols();

bool parse_A_instruction(const char *line, A_instruction *instr);

void parse_C_instruction(char *line, C_instruction *instr);

int parse(FILE * file, instruction *instructions);

void assemble(const char * file_name, instruction* instructions, int num_instructions);

opcode instruction_to_opcode(C_instruction instr);


#endif