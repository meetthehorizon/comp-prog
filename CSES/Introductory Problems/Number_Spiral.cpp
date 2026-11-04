#include <bits/stdc++.h>
using namespace std;

void solve();

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    solve();
  return 0;
}

void solve() {
  int x, y;
  cin >> x >> y;
  int z = max(x, y);
  long long ans = (1LL * z * z) - (z - 1);

  if (z % 2 == 1)
    ans += (y == z) ? z - x : y - z;
  else
    ans += (y == z) ? x - z : z - y;

  cout << ans << '\n';
}
