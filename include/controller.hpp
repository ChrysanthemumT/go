#pragma once
#include "game.hpp"
#include <memory>

class Controller {
public:
  Controller() {};
  void run();

private:
  std::unique_ptr<Game> game;
};
