#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  if (!(cin >> n))
    return 0;

  vector<long long> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + vec[i];
  }

  long long ans = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    long long left_cost = vec[i] * i - pre[i];
      long long right_cost = (pre[n] - pre[i + 1]) - vec[i] * (n - 1 - i);

    ans = min(ans, left_cost + right_cost);
  }

  cout << ans << "\n";
  return 0;
}
