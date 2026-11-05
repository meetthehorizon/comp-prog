#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  long long ans = 1;
  while (n--) {
    ans <<= 1;
    if (ans >= MOD)
      ans -= MOD;
  }

  cout << ans;
}
