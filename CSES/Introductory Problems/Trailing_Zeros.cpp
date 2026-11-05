#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;

  long long p = 5;
  while (p <= n) {
    ans += n / p;
    p *= 5;
  }
  cout << ans;
}
