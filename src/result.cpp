#include "result.hpp"

Result::Result(Board *board, Player *p1, Player *p2) { this->board = board; }

Player *Result::getP1() { return p1; }

Player *Result::getP2() { return p2; }

Result::OUTCOME Result::getOutcome() { return outcome; }

Board Result::getBoard() { return *board; }
