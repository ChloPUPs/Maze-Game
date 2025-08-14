#include <SDL2/SDL.h>

class Player {
  public:

  float speed;
  SDL_Rect rect;
  float velocity_x;
  float velocity_y;

  void update();

  Player();
  Player(float x, float y, float speed);
};