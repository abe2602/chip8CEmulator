#include "chip8_memory.h"
#include <stdbool.h>

static bool isOutOfMemoryBounds(int index)
{
    return index >= 0 && index < CHIP8_MEMORY_SIZE;
}

void chip8MemorySet(Chip8Memory *memory, int index, unsigned char value)
{
    if (!isOutOfMemoryBounds(index))
    {
        memory->memory[index] = value;
    }
}

unsigned char getChip8MemoryValue(Chip8Memory *memory, int index)
{
    if (!isOutOfMemoryBounds(index))
    {
        return memory->memory[index];
    }

    return '1';
}