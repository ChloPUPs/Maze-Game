#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  bool running = true;
  SDL_Event e;

  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_ESCAPE:
            running = false;
        }
      }
      else if (e.type == SDL_QUIT) {
        running = false;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return 0;
}