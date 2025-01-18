#include "game.hpp"
#include "result.hpp"
#include <memory>
#include <utility>

Game::Game() {
  board = std::make_shared<Board>(9);
  p1 = std::make_unique<Player>(1);
  p2 = std::make_unique<Player>(2);
  turnPlayer = p1.get();
}

void Game::makeMove(int x, int y) {
  if (x < 0 || y < 0 || x >= board->size() || y >= board->size())
    return;
  int captured = board->placeStones(*turnPlayer, std::make_pair(x, y));
  if (captured == -1) {
    return;
  }
  turnPlayer->capture(captured);
  changeTurn();
}

void Game::changeTurn() {
  if (turnPlayer == p1.get())
    turnPlayer = p2.get();
  else
    turnPlayer = p1.get();
}

bool Game::pass() {
  if (turnPlayer->getColour() == 1) {
    passState.first = true;
  } else {
    passState.second = true;
  }
  return passState.first && passState.second;
}

void Game::resetPass() {
  passState.first = false;
  passState.second = false;
}

std::unique_ptr<Result> Game::endGame() {
  std::unique_ptr<Result> result =
      std::make_unique<Result>(board.get(), p1.get(), p2.get());

  p1->capture(board->findDeadGroup(*p1));
  p2->capture(board->findDeadGroup(*p2));

  p1->increaseScore(board->countTerritory(*p1));
  p2->increaseScore(board->countTerritory(*p2));
  p1->increaseScore(-(p2->getPrisoners()));
  p2->increaseScore(-(p1->getPrisoners()));

  return std::move(result);
}

Player *Game::getTurnPlayer() { return turnPlayer; }

std::vector<std::vector<int>> Game::getBoard() { return board->getBoard(); }
