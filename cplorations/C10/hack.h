
#define NUM_PREDEFINED_SYMBOLS 23

#include <stdint.h>

typedef enum symbol_id
{
    SYM_R0 = 0,
    SYM_R1 = 1,
    SYM_R2 = 2,
    SYM_R3 = 3,
    SYM_R4 = 4,
    SYM_R5 = 5,
    SYM_R6 = 6,
    SYM_R7 = 7,
    SYM_R8 = 8,
    SYM_R9 = 9,
    SYM_R10 = 10,
    SYM_R11 = 11,
    SYM_R12 = 12,
    SYM_R13 = 13,
    SYM_R14 = 14,
    SYM_R15 = 15,
    SYM_SP = 0,
    SYM_LCL = 1,
    SYM_ARG = 2,
    SYM_THIS = 3,
    SYM_THAT = 4,
    SYM_SCREEN = 16384,
    SYM_KBD = 24576
} symbol_id;

typedef struct predefined_symbol
{
    char name[sizeof(char) * 10];
    int16_t address;

} predefined_symbol;

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {

    {"R0", SYM_R0},
    {"R1", SYM_R1},
    {"R2", SYM_R2},
    {"R3", SYM_R3},
    {"R4", SYM_R4},
    {"R5", SYM_R5},
    {"R6", SYM_R6},
    {"R7", SYM_R7},
    {"R8", SYM_R8},
    {"R9", SYM_R9},
    {"R10", SYM_R10},
    {"R11", SYM_R11},
    {"R12", SYM_R12},
    {"R13", SYM_R13},
    {"R14", SYM_R14},
    {"R15", SYM_R15},
    {"SP", SYM_SP},
    {"LCL", SYM_LCL},
    {"ARG", SYM_ARG},
    {"THIS", SYM_THIS},
    {"THAT", SYM_THAT},
    {"SCREEN", SYM_SCREEN},
    {"KBD", SYM_KBD}

};

typedef enum jump_id
{
    JMP_INVALID = -1,
    JMP_NULL,
    JMP_JGT,
    JMP_JEQ,
    JMP_JGE,
    JMP_JLT,
    JMP_JNE,
    JMP_JLE,
    JMP_JMP
} jump_id;

typedef enum dest_id
{
    DEST_INVALID = -1,
    DEST_NULL,
    DEST_M,
    DEST_D,
    DEST_MD,
    DEST_A,
    DEST_AM,
    DEST_AD,
    DEST_AMD
} dest_id;

typedef enum comp_id
{
    COMP_INVALID = -1,
    COMP_0 = 0b101010,
    COMP_1 = 0b111111,
    COMP_neg1 = 0b111010,
    COMP_D = 0b001100,
    COMP_A = 0b110000,
    COMP_notD = 0b001101,
    COMP_notA = 0b110001,
    COMP_negD = 0b001111,
    COMP_negA = 0b110011,
    COMP_Dplus1 = 0b011111,
    COMP_Aplus1 = 0b110111,
    COMP_Dmin1 = 0b001110,
    COMP_Amin1 = 0b110010,
    COMP_DplusA = 0b000010,
    COMP_DminA = 0b010011,
    COMP_AminD = 0b000111,
    COMP_DandA = 0b000000,
    COMP_DorA = 0b010101,

    COMP_M = 0b110000,
    COMP_notM = 0b110001,
    COMP_negM = 0b110011,
    COMP_Mplus1 = 0b110111,
    COMP_Mmin1 = 0b110010,
    COMP_DplusM = 0b000010,
    COMP_DminM = 0b010011,
    COMP_MminD = 0b010011,
    COMP_DandM = 0b000000,
    COMP_DorM = 0b010101,
} comp_id;

static inline jump_id str_to_jumpid(const char *s)
{
    jump_id id = JMP_INVALID;

    if (s == NULL)
    {
        id = JMP_NULL;
    }
    else if (strcmp(s, "JGT") == 0)
    {
        id = JMP_JGT;
    }
    else if (strcmp(s, "JEQ") == 0)
    {
        id = JMP_JEQ;
    }
    else if (strcmp(s, "JGE") == 0)
    {
        id = JMP_JGE;
    }
    else if (strcmp(s, "JLT") == 0)
    {
        id = JMP_JLT;
    }
    else if (strcmp(s, "JNE") == 0)
    {
        id = JMP_JNE;
    }
    else if (strcmp(s, "JLE") == 0)
    {
        id = JMP_JLE;
    }
    else if (strcmp(s, "JMP") == 0)
    {
        id = JMP_JMP;
    }

    return id;
};

static inline dest_id str_to_destid(const char *s)
{
    dest_id id = DEST_INVALID;

    if (s == NULL)
    {
        id = DEST_NULL;
    }
    else if (strcmp(s, "M") == 0)
    {
        id = DEST_M;
    }
    else if (strcmp(s, "D") == 0)
    {
        id = DEST_D;
    }
    else if (strcmp(s, "MD") == 0)
    {
        id = DEST_MD;
    }
    else if (strcmp(s, "A") == 0)
    {
        id = DEST_A;
    }
    else if (strcmp(s, "AM") == 0)
    {
        id = DEST_AM;
    }
    else if (strcmp(s, "AD") == 0)
    {
        id = DEST_AD;
    }
    else if (strcmp(s, "AMD") == 0)
    {
        id = DEST_AMD;
    }

    return id;
};

static inline comp_id str_to_compid(const char *s, int *a)
{
    comp_id id = COMP_INVALID;

    if (strcmp(s, "0") == 0)
    {
        id = COMP_0;
        *a = 0;
    }
    else if (strcmp(s, "1") == 0)
    {
        id = COMP_1;
        *a = 0;
    }
    else if (strcmp(s, "-1") == 0)
    {
        id = COMP_neg1;
        *a = 0;
    }
    else if (strcmp(s, "D") == 0)
    {
        id = COMP_D;
        *a = 0;
    }
    else if (strcmp(s, "A") == 0)
    {
        id = COMP_A;
        *a = 0;
    }
    else if (strcmp(s, "!D") == 0)
    {
        id = COMP_notD;
        *a = 0;
    }
    else if (strcmp(s, "!A") == 0)
    {
        id = COMP_notA;
        *a = 0;
    }
    else if (strcmp(s, "-D") == 0)
    {
        id = COMP_negD;
        *a = 0;
    }
    else if (strcmp(s, "-A") == 0)
    {
        id = COMP_negA;
        *a = 0;
    }
    else if (strcmp(s, "D+1") == 0)
    {
        id = COMP_Dplus1;
        *a = 0;
    }
    else if (strcmp(s, "A+1") == 0)
    {
        id = COMP_Aplus1;
        *a = 0;
    }
    else if (strcmp(s, "D-1") == 0)
    {
        id = COMP_Dmin1;
        *a = 0;
    }
    else if (strcmp(s, "A-1") == 0)
    {
        id = COMP_Amin1;
        *a = 0;
    }
    else if (strcmp(s, "D+A") == 0)
    {
        id = COMP_DplusA;
        *a = 0;
    }
    else if (strcmp(s, "D-A") == 0)
    {
        id = COMP_DminA;
        *a = 0;
    }
    else if (strcmp(s, "A-D") == 0)
    {
        id = COMP_AminD;
        *a = 0;
    }
    else if (strcmp(s, "D&A") == 0)
    {
        id = COMP_DandA;
        *a = 0;
    }
    else if (strcmp(s, "D|A") == 0)
    {
        id = COMP_DorA;
        *a = 0;
    }

    else if (strcmp(s, "M") == 0)
    {
        id = COMP_M;
        *a = 1;
    }else if (strcmp(s, "!M") == 0)
    {
        id = COMP_notM;
        *a = 1;
    }else if (strcmp(s, "-M") == 0)
    {
        id = COMP_negM;
        *a = 1;
    }else if (strcmp(s, "M+1") == 0)
    {
        id = COMP_Mplus1;
        *a = 1;
    }else if (strcmp(s, "M-1") == 0)
    {
        id = COMP_Mmin1;
        *a = 1;
    }else if (strcmp(s, "D+M") == 0)
    {
        id = COMP_DplusM;
        *a = 1;
    }else if (strcmp(s, "D-M") == 0)
    {
        id = COMP_DminM;
        *a = 1;
    }else if (strcmp(s, "M-D") == 0)
    {
        id = COMP_MminD;
        *a = 1;
    }else if (strcmp(s, "M&D") == 0)
    {
        id = COMP_DandM;
        *a = 1;
    }else if (strcmp(s, "D|M") == 0)
    {
        id = COMP_DorM;
        *a = 1;
    }

    return id;
    
};
