#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  for (long long i = 1; i <= n; ++i) {
    
    cout << (i * i * i * i - 9 * i * i) / 2 + 12 * i - 8 << '\n';
  }
}
