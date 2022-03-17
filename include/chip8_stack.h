#ifndef CHIP8_STACK_H
#define CHIP8_STACK_H

#include "config.h"

typedef struct _CHIP8 Chip8;
typedef struct _CHIP8_STACK
{
    unsigned short values[CHIP8_TOTAL_STACK_DEPTH]; 
} Chip8Stack;

void chip8StackPush(Chip8* chip8, unsigned short value);

unsigned short chip8StackPop(Chip8* chip8);

#endif