#include "player.hpp"

Player::Player(int colour) {
  this->colour = colour;
  if (colour == 1) {
    stones = 181;
  } else
    stones = 180;
}

int Player::getColour() { return colour; }

int Player::getStones() const { return stones; };

void Player::capture(int cap) { captured += cap; }

void Player::increaseScore(int s) { score += s; }
