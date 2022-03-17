#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include "config.h"

typedef struct _CHIP8_MEMORY
{
    unsigned char memory[CHIP8_MEMORY_SIZE];
} Chip8Memory;

void chip8MemorySet(Chip8Memory* memory, int index, unsigned char value);
unsigned char getChip8MemoryValue(Chip8Memory* memory, int index);

#endif