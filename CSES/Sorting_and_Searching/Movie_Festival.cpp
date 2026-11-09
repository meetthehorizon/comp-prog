#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto& p : vp)
    cin >> p.first >> p.second;

  sort(vp.begin(), vp.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  int ans = 0, last = -1;
  for (auto [x, y] : vp) {
    if (last <= x)
      ++ans, last = y;
  }

  cout << ans;
}
