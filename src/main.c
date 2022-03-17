#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char **argv)
{
    Chip8 chip8;
    chip8.registers.stackPointer = 0;

    chip8StackPush(&chip8, 0xff);
    chip8StackPush(&chip8, 0xaa);

    printf("%x\n", chip8StackPop(&chip8));
    printf("%x\n", chip8StackPop(&chip8));

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER,
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_TEXTUREACCESS_TARGET
    );

    int shouldFinisheLoop = 0;

    while(1) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                shouldFinisheLoop = 1;
                break;
            }
        }

        if(shouldFinisheLoop == 1) {
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