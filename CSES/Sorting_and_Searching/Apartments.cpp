#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> app(n);
  for (auto& a : app)
    cin >> a;
  vector<int> pos(m);
  for (auto& p : pos)
    cin >> p;

  sort(app.begin(), app.end());
  sort(pos.begin(), pos.end());

  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (app[i] - k <= pos[j] && pos[j] <= app[i] + k)
      ++i, ++j, ++ans;
    else if (pos[j] < app[i] - k)
      ++j;
    else if (pos[j] > app[i] + k)
      ++i;
    else
      ++i;
  }

  cout << ans;
}
