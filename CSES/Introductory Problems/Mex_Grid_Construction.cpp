#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  auto val = [&grid](int i, int j) -> int {
    vector<int> vec;
    for (int x = 0; x < i; ++x)
      vec.push_back(grid[x][j]);
    for (int y = 0; y < j; y++)
      vec.push_back(grid[i][y]);

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int x = 0; x < vec.size(); ++x)
      if (x != vec[x])
        return x;
    return vec.size();
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (grid[i][j] = val(i, j)) << ' ';
    }
    cout << endl;
  }
}
