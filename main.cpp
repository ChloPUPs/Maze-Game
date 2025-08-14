#include <iostream>

#include <SDL2/SDL.h>
#include "player.h"

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  // Window and renderer

  SDL_Window* window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // Game things

  Player player(0, 0, 10);

  bool isHoldingRightMove = false;
  bool isHoldingLeftMove = false;

  // Event loop

  bool running = true;
  SDL_Event e;

  while (running) {
    // Get input

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_ESCAPE:
            running = false;
            break;
          
          case SDLK_a:
            isHoldingLeftMove = true;
            break;
          case SDLK_d:
            isHoldingRightMove = true;
            break;
        }
      }
      else if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
          case SDLK_a:
            isHoldingLeftMove = false;
            break;
          case SDLK_d:
            isHoldingRightMove = false;
            break;
        }
      }
      else if (e.type == SDL_QUIT) {
        running = false;
      }
    }

    // Physics

    player.velocity_x = (isHoldingRightMove - isHoldingLeftMove) * player.speed;

    player.update();
    //std::cout << player.rect.x << "x " << player.rect.y << "y\n";

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