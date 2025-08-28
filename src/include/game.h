#pragma once

#include <map>
#include <string>

#include <SDL2/SDL.h>

#include "player.h"

class Game {
    private:

    SDL_Window *window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    std::map<std::string, bool> keyHeld = {
        {"right", false},
        {"left", false},
        {"down", false},
        {"up", false}
    };

    Player player;

    public:

    void loop();
    void quit();

    Game() {
        player.speed = 300;
    }
};
