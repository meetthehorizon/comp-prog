#include <bits/stdc++.h>
using namespace std;

void solve();

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

void solve() {
  int x, y;
  cin >> x >> y;

  int a = x + y;
  if (a % 3)
    cout << "NO\n";
  else {
    a /= 3;
    if (a <= x && a <= y)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
