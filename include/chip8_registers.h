#ifndef CHIP8_REGISTERS_H
#define CHIP8_REGISTERS_H

#include "config.h"

typedef struct _CHIP8_REGISTERS
{
    unsigned char V[CHIP8_TOTAL_REGISTERS]; // 16 registradores de 8 bits
    unsigned short I;
    unsigned char delayTimer;
    unsigned char soundTimer;
    unsigned short programCounter;
    unsigned char stackPointer;
} Chip8Registers;

#endif