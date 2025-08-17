#include <iostream>

#include <SDL2/SDL.h>
#include "include/player.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    // Window and renderer

    SDL_Window *window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Game things

    Player player(0, 0, 300);

    bool isHoldingMoveRight = false;
    bool isHoldingMoveLeft = false;
    bool isHoldingMoveDown = false;
    bool isHoldingMoveUp = false;

    // Event loop

    Uint64 currentTick;
    Uint64 lastTick;
    float deltaTime;

    bool running = true;
    SDL_Event e;

    while (running) {
        lastTick = currentTick;
        currentTick = SDL_GetTicks64();
        deltaTime = (currentTick - lastTick) / 1000.0f;

        // std::cout << deltaTime << ' ' << (currentTick - lastTick) << '\n';

        // Get input

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    break;

                case SDLK_a:
                    isHoldingMoveLeft = true;
                    break;
                case SDLK_d:
                    isHoldingMoveRight = true;
                    break;
                case SDLK_w:
                    isHoldingMoveUp = true;
                    break;
                case SDLK_s:
                    isHoldingMoveDown = true;
                    break;
                }
            }
            else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                case SDLK_a:
                    isHoldingMoveLeft = false;
                    break;
                case SDLK_d:
                    isHoldingMoveRight = false;
                    break;
                case SDLK_w:
                    isHoldingMoveUp = false;
                    break;
                case SDLK_s:
                    isHoldingMoveDown = false;
                    break;
                }
            }
            else if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        // Physics

        player.velocity_x = (isHoldingMoveRight - isHoldingMoveLeft) * player.speed;
        player.velocity_y = (isHoldingMoveDown - isHoldingMoveUp) * player.speed;

        player.updatePhysics(deltaTime);
        // std::cout << player.rect.x << "x " << player.rect.y << "y\n";

        // Render stuff

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &player.rect);

        SDL_RenderPresent(renderer);
    }

    // Destroy everything

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}