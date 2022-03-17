#include "chip8_memory.h"

static int isOutOfMemoryBounds(int index)
{
    if (index >= 0 && index < CHIP8_MEMORY_SIZE)
    {
        return 0;
    }

    return 1;
}

void chip8MemorySet(Chip8Memory *memory, int index, unsigned char value)
{
    if (isOutOfMemoryBounds(index) == 0)
    {
        memory->memory[index] = value;
    }
}

unsigned char getChip8MemoryValue(Chip8Memory *memory, int index)
{
    if (isOutOfMemoryBounds(index) == 0)
    {
        return memory->memory[index];
    }
    return '1';
}