#pragma once
#include "game.hpp"
#include "ui.hpp"
#include <memory>

class Controller {
public:
  Controller() {};
  void run();

private:
  std::unique_ptr<Game> game;
  std::unique_ptr<GoUI> ui;
};
