#include "controller.hpp"
#include "game.hpp"
#include <memory>

void Controller::run() {
  game = std::make_unique<Game>();
  while (1) {
    int x, y;
    scanf("%d %d", &x, &y);
    game->makeMove(x, y);
  }
}
