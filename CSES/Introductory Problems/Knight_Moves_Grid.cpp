#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  if (!(cin >> n))
    return 0;

  vector<int> dis(n * n, -1);
  dis[0] = 0;

  vector<pair<int, int>> del = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                {1, -2},  {1, 2},  {2, -1},  {2, 1}};

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    int r = v / n;
    int c = v % n;

    for (auto [dr, dc] : del) {
      int nr = r + dr;
      int nc = c + dc;

      if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
        int u = nr * n + nc;
        if (dis[u] == -1) {
          dis[u] = dis[v] + 1;
          q.push(u);
        }
      }
    }
  }

  for (int i = 0; i < n * n; ++i) {
    if (i && (i % n == 0))
      cout << '\n';
    cout << dis[i] << (i % n == n - 1 ? "" : " ");
  }
  cout << '\n';

  return 0;
}
