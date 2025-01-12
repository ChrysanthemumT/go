#include "board.hpp"
#include "iostream"

std::vector<int> dv = {-1, 0, 1, 0};
std::vector<int> dh = {0, 1, 0, -1};

int Board::placeStones(Player &player, std::pair<int, int> coord) {
  if (!board[coord.first][coord.second]) {
    board[coord.first][coord.second] = player.getColour();
  }
  draw();
  return captureStones(player);
}

int Board::captureStones(Player &player) {
  int captured = 0;
  int cc = 0;
  std::vector<std::vector<int>> visited(board.size(),
                                        std::vector<int>(board.size(), 0));
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      if (!visited[i][j]) {
        auto [libertyFound, size] = floodfill(visited, cc, {i, j});
        if (!libertyFound)
          captured += size;
      }
    }
  }

  return captured;
}

void Board::draw() {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      if (j > 0)
        std::cout << "─";
      std::cout << board[i][j];
    }
    std::cout << "\n";
    if (i == board.size() - 1)
      continue;
    for (int j = 0; j < board.size(); j++) {
      if (j > 0)
        std::cout << " ";
      std::cout << "⎸";
    }
    std::cout << "\n";
  }
};

std::pair<bool, int> Board::floodfill(std::vector<std::vector<int>> &visited,
                                      int cc, std::pair<int, int> curr) {
  int x = curr.first, y = curr.second, count = 0;
  visited[x][y] = true;
  bool libertyFound = false;
  for (int i = 0; i < 4; i++) {
    int nv = dv[i] + x, nh = dh[i] + y;
    if (nv < 0 || nh < 0 || nv >= board.size() || nh <= board.size())
      continue;
    if (visited[nv][nh])
      continue;
    if (board[nv][nh] == 0) {
      return {true, 0};
    }
    if (board[nv][nh] == board[x][y]) {
      auto [flag, rcount] = floodfill(visited, cc, {nv, nh});
      libertyFound |= flag;
      count += 1 + rcount;
    }
  }
  return {libertyFound, count};
}
