#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> vp;

  while (n--) {
    int i, o;
    cin >> i >> o;
    vp.push_back({i, -1});
    vp.push_back({o, 1});
  }
  sort(vp.begin(), vp.end());

  int ans = 0, curr = 0;
  for (auto& [first, second] : vp) {
    if (second == -1)
      ++curr;
    else
      --curr;
    ans = max(ans, curr);
  }
  cout << ans << '\n';
}
