#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "chip8_memory.h"
#include "chip8_registers.h"
#include "chip8_stack.h"
#include "chip8_keyboard.h"

typedef struct _CHIP8
{
    Chip8Memory memory;
    Chip8Registers registers;
    Chip8Stack stack;
    Chip8Keyboard keyboard;
} Chip8;

void chip8Init(Chip8* chip8);

#endif