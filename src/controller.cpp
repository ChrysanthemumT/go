#include "controller.hpp"
#include "game.hpp"
#include <SDL.h>
#include <SDL_events.h>
#include <iostream>
#include <memory>

void Controller::run() {
  game = std::make_unique<Game>();
  ui = std::make_unique<GoUI>();
  if (!ui) {
    std::cout << "Failed to create UI" << std::endl;
    return;
  }
  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        std::pair<int, int> coord = ui->translateClick({mouseX, mouseY});
        std::cout << "[" << coord.first << " " << coord.second << "]"
                  << std::endl;
        game->makeMove(coord.first, coord.second);
        break;
      }
    }
    ui->drawBoard(game->getBoard());
    SDL_Delay(16);
  }
}
