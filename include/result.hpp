#pragma once
#include "board.hpp"
#include "player.hpp"

class Result {
public:
  enum OUTCOME { WIN, LOST, DRAW };
  Result(Board *board, Player *p1, Player *p2);
  OUTCOME getOutcome();
  Player *getP1();
  Player *getP2();
  Board getBoard();
  void determineWinner();

private:
  OUTCOME outcome;
  Player *p1;
  Player *p2;
  Board *board;
};
