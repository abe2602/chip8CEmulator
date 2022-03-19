#include "chip8_keyboard.h"

static bool isChip8KeyboardInbounds(int key) {
    return key >= 0 && key < CHIP8_TOTAL_KEYS;
}

int chip8KeyboardMap(const char *map, char key)
{
    for(int i = 0; i < CHIP8_TOTAL_KEYS; i++) {
        if(map[i] == key) {
            return i;
        }
    }

    return -1;
}

void chip8KeyboardKeyDown(Chip8Keyboard *keyboard, int key)
{
    keyboard->keyboard[key] = true;
}

void chip8KeyboardKeyUp(Chip8Keyboard *keyboard, int key)
{
    keyboard->keyboard[key] = false;
}

bool isChip8KeyboardKeyDown(Chip8Keyboard *keyboard, int key)
{
    return keyboard->keyboard[key];
}