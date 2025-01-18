#include "ui.hpp"
#include "circle.hpp"
#include <SDL.h>
#include <SDL_render.h>
#include <iostream>

GoUI::GoUI() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Go Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if (!window) {
    std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    return;
  }
}

GoUI::~GoUI() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void GoUI::drawBoard(std::vector<std::vector<int>> board) {
  SDL_SetRenderDrawColor(renderer, 222, 184, 135, 255); // Wooden color
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  int cellSize = WINDOW_WIDTH / (BOARD_SIZE + 1);
  for (int i = 0; i <= BOARD_SIZE; i++) {
    SDL_RenderDrawLine(renderer, i * cellSize, cellSize, i * cellSize,
                       BOARD_SIZE * cellSize);
    SDL_RenderDrawLine(renderer, cellSize, i * cellSize, BOARD_SIZE * cellSize,
                       i * cellSize);
  }

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      drawStone(board[i][j], {i + 1, j + 1});
    }
  }

  SDL_RenderPresent(renderer);
}

void GoUI::drawStone(int colour, std::pair<int, int> Coord) {

  if (colour == 0)
    return;
  if (colour == 2) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  } else {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  }
  int cellSize = WINDOW_WIDTH / (BOARD_SIZE + 1);
  int radius = cellSize / 3;

  SDL_RenderDrawCircle(renderer, cellSize * Coord.first,
                       cellSize * Coord.second, radius);
  SDL_RenderFillCircle(renderer, cellSize * Coord.first,
                       cellSize * Coord.second, radius);
}

std::pair<int, int> GoUI::translateClick(std::pair<int, int> mouseCoord) {

  int cellSize = WINDOW_WIDTH / (BOARD_SIZE + 1);
  int radius = cellSize / 3;
  std::pair<int, int> closestPoint = {-1, -1};

  for (int i = 1; i <= BOARD_SIZE; i++) {
    for (int j = 1; j <= BOARD_SIZE; j++) {

      int pointX = i * cellSize, pointY = j * cellSize,
          mouseX = mouseCoord.first, mouseY = mouseCoord.second;

      double distance = pow(mouseCoord.first - pointX, 2) +
                        pow(mouseCoord.second - pointY, 2);
      if (distance <= pow(radius, 2)) {
        closestPoint = {i - 1, j - 1};
      }
    }
  }
  return closestPoint;
}
