#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8_keyboard.h"

const char keyboardMap[CHIP8_TOTAL_KEYS] = {
    SDLK_0,
    SDLK_1,
    SDLK_2,
    SDLK_3,
    SDLK_4,
    SDLK_5,
    SDLK_6,
    SDLK_7,
    SDLK_8,
    SDLK_9,
    SDLK_a,
    SDLK_b,
    SDLK_c,
    SDLK_d,
    SDLK_e,
    SDLK_f,
};

int main(int argc, char **argv)
{
    Chip8 chip8;
    chip8Init(&chip8);
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_TEXTUREACCESS_TARGET);

    int shouldFinisheLoop = 0;

    while (1)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            char key = event.key.keysym.sym;

            switch (event.type)
            {
            case SDL_QUIT:
                shouldFinisheLoop = 1;
                break;

            case SDL_KEYDOWN:
            {
                int virtualKey = chip8KeyboardMap(keyboardMap, key);

                if (virtualKey != -1)
                {
                    chip8KeyboardKeyDown(&chip8.keyboard, virtualKey);
                }
            }
            break;

            case SDL_KEYUP:
            {
                int virtualKey = chip8KeyboardMap(keyboardMap, key);

                if (virtualKey != -1)
                {
                    chip8KeyboardKeyUp(&chip8.keyboard, virtualKey);
                }
            }
            break;

            default:
                break;
            }
        }

        if (shouldFinisheLoop == 1)
        {
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_Rect rectangle;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

        rectangle.x = 0;
        rectangle.y = 0;
        rectangle.w = 40;
        rectangle.h = 40;

        SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    return 0;
}