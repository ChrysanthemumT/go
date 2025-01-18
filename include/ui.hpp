#pragma once
#include <SDL.h>
#include <vector>

class GoUI {
public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  const int WINDOW_WIDTH = 800;
  const int WINDOW_HEIGHT = 800;
  const int BOARD_SIZE = 9;
  GoUI();
  ~GoUI();
  void drawBoard(std::vector<std::vector<int>> board);
  void drawStone(int color, std::pair<int, int> coord);
  std::pair<int, int> translateClick(std::pair<int, int> coord);

private:
  void handleEvents();
};
