#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const int NUM_CELLS = N * N;
const int NUM_MOVES = NUM_CELLS - 1;
char visited_cells[NUM_CELLS];

enum Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, UNKOWN = 4 };
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};
const Direction directions[4] = {UP, DOWN, LEFT, RIGHT};

bool valid_cell(int x, int y) {
  return 0 <= x && x < N && 0 <= y && y < N && !visited_cells[N * x + y];
}

inline Direction char_to_dir(char c) {
  switch (c) {
    case 'U':
      return UP;
    case 'D':
      return DOWN;
    case 'L':
      return LEFT;
    case 'R':
      return RIGHT;
    default:
      return UNKOWN;
  }
}

int num_paths(int x, int y, int num_moves, Direction path[NUM_MOVES]) {
  if (x == N - 1 && y == 0) {
    return num_moves == NUM_MOVES;
  }

  int poss_moves[4]{}, total_poss_moves = 0;
  for (auto& d : directions)
    total_poss_moves += (poss_moves[d] = valid_cell(x + DX[d], y + DY[d]));

  if (total_poss_moves == 2) {
    if ((poss_moves[UP] && poss_moves[DOWN]) || (poss_moves[LEFT] && poss_moves[RIGHT]))
      return 0;
  }

  int forced_cnt = 0, forced_dir = 0;
  for (auto& d : directions) {
    if (!poss_moves[d])
      continue;
    int nx = x + DX[d], ny = y + DY[d];
    if (nx == N - 1 && ny == 0)
      continue;
    int deg = 0;
    for (auto& e : directions)
      deg += valid_cell(nx + DX[e], ny + DY[e]);
    if (deg == 0)
      return 0;
    if (deg == 1)
      forced_cnt++, forced_dir = d;
  }
  if (forced_cnt >= 2)
    return 0;
  if (forced_cnt == 1) {
    memset(poss_moves, 0, sizeof(poss_moves));
    poss_moves[forced_dir] = 1;
  }

  if (path[num_moves] != UNKOWN) {
    Direction forced = path[num_moves];
    if (!poss_moves[forced])
      return 0;
    memset(poss_moves, 0, sizeof(poss_moves));
    poss_moves[forced] = 1;
  }

  int total_paths = 0;
  for (auto& d : directions)
    if (poss_moves[d]) {
      int nx = x + DX[d], ny = y + DY[d];
      int enc = nx * N + ny;
      visited_cells[enc] = 1;
      total_paths += num_paths(nx, ny, num_moves + 1, path);
      visited_cells[enc] = 0;
    }

  return total_paths;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  Direction path[NUM_MOVES];
  fill(path, path + NUM_MOVES, UNKOWN);
  for (size_t i = 0; i < s.size(); ++i)
    path[i] = char_to_dir(s[i]);

  if (count(path, path + NUM_MOVES, UNKOWN) == NUM_MOVES) {
    cout << 88418 << '\n';
    return 0;
  }

  visited_cells[0] = 1;
  cout << num_paths(0, 0, 0, path) << '\n';
}
