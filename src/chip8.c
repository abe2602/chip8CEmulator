#include <memory.h>
#include "chip8.h"

void chip8Init(Chip8* chip8) {
    memset(chip8, 0, sizeof(Chip8));
}