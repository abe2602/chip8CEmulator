#include "chip8_stack.h"
#include "chip8.h"

static int chip8IsStackInBounds(Chip8 *chip8)
{
    if (chip8->registers.stackPointer < CHIP8_TOTAL_STACK_DEPTH)
    {
        return 0;
    }
    return 1;
}

void chip8StackPush(Chip8 *chip8, unsigned short value)
{
    if (chip8IsStackInBounds(chip8) == 1)
    {
        return;
    }

    chip8->stack.values[chip8->registers.stackPointer] = value;
    chip8->registers.stackPointer++;
}

unsigned short chip8StackPop(Chip8 *chip8)
{
    chip8->registers.stackPointer--;
    return chip8->stack.values[chip8->registers.stackPointer];
}