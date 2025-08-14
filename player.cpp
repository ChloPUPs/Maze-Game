#include "player.h"

void Player::updatePhysics(float deltaTime) {
  rect.x += (int) (velocity_x * deltaTime);
  rect.y += (int) (velocity_y * deltaTime);
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