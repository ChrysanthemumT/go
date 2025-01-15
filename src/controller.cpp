#include "controller.hpp"
#include "game.hpp"
#include <memory>

void Controller::run() {
  game = std::make_unique<Game>();
  while (1) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x == -1 && y == -1) {
      bool agreedToPass = game->pass();
      if (agreedToPass) {
        // end game
        game->endGame();
        break;
      }
    } else {
      game->resetPass();
      game->makeMove(x, y);
    }
  }
}
