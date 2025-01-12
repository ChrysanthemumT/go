#pragma once
class Player {
public:
  Player(int colour);
  int getStones() const;
  void capture(int cap);
  void increaseScore(int points);
  int getColour();

private:
  int stones;
  int captured;
  int score;
  int colour;
};
