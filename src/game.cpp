#include "include/game.h"

void Game::loop() {
    Uint64 currentTick;
    Uint64 lastTick;
    float deltaTime;

    running = true;

    SDL_Event e;

    while (running) {
        lastTick = currentTick;
        currentTick = SDL_GetTicks64();
        deltaTime = (currentTick - lastTick) / 1000.0f;

        //std::cout << deltaTime << ' ' << (currentTick - lastTick) << '\n';

        // Handle Events

        handleEvents(e);

        // Physics

        player.velocity_x = (keyHeld.at("right") - keyHeld.at("left")) * player.speed;
        player.velocity_y = (keyHeld.at("down") - keyHeld.at("up")) * player.speed;

        player.updatePhysics(deltaTime);
        //std::cout << player.rect.x << "x " << player.rect.y << "y\n";

        // Render stuff

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &player.rect);

        SDL_RenderPresent(renderer);
    }
}

void Game::handleEvents(SDL_Event e) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;

                case SDLK_a:
                    keyHeld.at("left") = true;
                    break;
                case SDLK_d:
                    keyHeld.at("right") = true;
                    break;
                case SDLK_w:
                    keyHeld.at("up") = true;
                    break;
                case SDLK_s:
                    keyHeld.at("down") = true;
                    break;
            }
        }
        else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_a:
                    keyHeld.at("left") = false;
                    break;
                case SDLK_d:
                    keyHeld.at("right") = false;
                    break;
                case SDLK_w:
                    keyHeld.at("up") = false;
                    break;
                case SDLK_s:
                    keyHeld.at("down") = false;
                    break;
            }
        }
        else if (e.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Game::quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
