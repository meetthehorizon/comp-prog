#include <bits/stdc++.h>
using namespace std;

int NUM_ROWS = 8;

bool can_add(vector<pair<int, int>>& queen_positions, pair<int, int> new_queen_pos) {
  for (auto& u : queen_positions)
    if (u.first == new_queen_pos.first || u.second == new_queen_pos.second)
      return false;
    else if (abs(u.first - new_queen_pos.first) == abs(u.second - new_queen_pos.second))
      return false;

  return true;
}

int backtrack(int row, vector<pair<int, int>>& queen_positions, set<int>& invalid_pos) {
  if (row == NUM_ROWS) {
    return 1;
  }

  int tot = 0;
  for (int col = 0; col < NUM_ROWS; ++col)
    if (!invalid_pos.count(row * NUM_ROWS + col)) {
      if (can_add(queen_positions, make_pair(row, col))) {
        queen_positions.push_back({row, col});
        tot += backtrack(row + 1, queen_positions, invalid_pos);
        queen_positions.pop_back();
      }
    }
  return tot;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<int> invalid_pos;
  for (int row = 0; row < NUM_ROWS; ++row) {
    string x;
    cin >> x;
    for (int col = 0; col < 8; ++col) {
      if (x[col] == '*')
        invalid_pos.insert(NUM_ROWS * row + col);
    }
  }

  vector<pair<int, int>> vp;
  cout << backtrack(0, vp, invalid_pos);
}
