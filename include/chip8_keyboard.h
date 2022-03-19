#ifndef CHIP8_KEYBOARD_H
#define CHIP8_KEYBOARD_H

#include <stdbool.h>
#include "config.h"

typedef struct _CHIP8_KEYBOARD
{
    bool keyboard[CHIP8_TOTAL_KEYS];
} Chip8Keyboard;

int chip8KeyboardMap(const char* map, char key); //transforma teclas "de verdade" em virtuais
void chip8KeyboardKeyDown(Chip8Keyboard *keyboard, int key);
void chip8KeyboardKeyUp(Chip8Keyboard *keyboard, int key);
bool isChip8KeyboardKeyDown(Chip8Keyboard *keyboard, int key);

#endif