#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  long long sum = 1LL * n * (n + 1) / 2;
  if (sum & 1) {
    cout << "NO";
    return 0;
  }
  sum >>= 1;

  set<int> a;
  for (int i = n; i > 0; --i) {
    if (i <= sum) {
      sum -= i;
      a.insert(i);
    }
    i = min(1LL * i, sum + 1);
  }

  cout << "YES\n";

  cout << a.size() << '\n';
  for (auto& v : a) {
    cout << v << ' ';
  }
  cout << '\n';

  cout << n - a.size() << '\n';
  for (int i = 1; i <= n; ++i)
    if (!a.count(i))
      cout << i << ' ';
  cout << '\n';
}
