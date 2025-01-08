#include "player.hpp"

Player::Player(int colour) {
  this->colour = colour;
  if (colour) {
    stones = 181;
  } else
    stones = 180;
}
