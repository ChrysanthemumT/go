#include "board.hpp"
#include "iostream"

std::vector<int> dv = {-1, 0, 1, 0};
std::vector<int> dh = {0, 1, 0, -1};

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
  visited[x][y] = cc;
  bool libertyFound = false;
  for (int i = 0; i < 4; i++) {
    int nv = dv[i] + x, nh = dh[i] + y;
    if (nv < 0 || nh < 0 || nv >= board.size() || nh >= board.size())
      continue;
    if (visited[nv][nh])
      continue;
    if (board[nv][nh] == 0) {
      libertyFound = true;
    }
    if (board[nv][nh] == board[x][y]) {
      auto [flag, rcount] = floodfill(visited, cc, {nv, nh});
      libertyFound |= flag;
      count += 1 + rcount;
    }
  }
  return {libertyFound, count};
}

int Board::captureStones(Player &player) {
  int captured = 0;
  int cc = 1;
  std::vector<int> toRemove;
  std::vector<std::vector<int>> visited(board.size(),
                                        std::vector<int>(board.size(), 0));
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      if (!visited[i][j] && board[i][j] && board[i][j] != player.getColour()) {
        auto [libertyFound, size] = floodfill(visited, cc, {i, j});
        if (!libertyFound) {
          captured += size;
          std::cout << libertyFound << " " << size << std::endl;
          toRemove.push_back(cc);
        }
        cc++;
      }
    }
  }

  std::cout << toRemove.size() << std::endl;
  for (auto ccc : toRemove) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board.size(); j++) {
        if (visited[i][j] == ccc)
          board[i][j] = 0;
      }
    }
  }

  return captured;
}

bool Board::suicide(Player &player, std::pair<int, int> curr) {
  int x = curr.first, y = curr.second;
  bool libertyFound = false;
  for (int i = 0; i < 4; i++) {
    int nv = x + dv[i], nh = y + dh[i];
    if (nv < 0 || nh < 0 || nv >= board.size() || nh >= board.size())
      continue;
    if (board[nv][nh] == 0) {
      libertyFound |= 1;
      break;
    }
  }
  return !libertyFound;
}

int Board::placeStones(Player &player, std::pair<int, int> coord) {
  int x = coord.first, y = coord.second;
  if (!board[coord.first][coord.second]) {
    board[coord.first][coord.second] = player.getColour();
  }
  int captured = captureStones(player);
  if (!captured && suicide(player, coord)) {
    board[x][y] = 0;
    draw();
    return -1;
  }
  draw();
  return captured;
}
