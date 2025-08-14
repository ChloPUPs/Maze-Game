#include "player.h"

void Player::update() {
  rect.x += velocity_x;
  rect.y += velocity_y;
}

Player::Player() : speed(0), velocity_x(0), velocity_y(0) {
  rect.x = 0;
  rect.y = 0;
  rect.w = 30;
  rect.h = 30;
}

Player::Player(float x, float y, float speed) : speed(speed), velocity_x(0), velocity_y(0) {
  rect.x = x;
  rect.y = y;
  rect.w = 30;
  rect.h = 30;
}