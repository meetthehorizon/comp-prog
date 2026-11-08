#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto& v : vec)
    cin >> v;

  long long min_diff = INT_MAX, tot = accumulate(vec.begin(), vec.end(), 0LL);
  for (long long mask = 0; mask < (1LL << n); ++mask) {
    long long x = 0;

    for (long long j = 0; j < n; ++j)
      if ((mask >> j) & 1)
        x += vec[j];

    min_diff = min(min_diff, abs(tot - 2 * x));
  }

  cout << min_diff << '\n';
}
