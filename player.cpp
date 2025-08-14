#include "player.h"

class Player {
  public:
  float x, y;
  SDL_Rect rect;

  Player(float x, float y) : x(x), y(y) {}
};