#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> vec(n);
  for (int i = 1; i <= n; ++i) {
    cin >> vec[i - 1].first;
    vec[i - 1].second = i;
  }

  sort(vec.begin(), vec.end());
  for (int i = 0, j = n - 1; i < j;) {
    int sum = vec[i].first + vec[j].first;
    if (x > sum)
      ++i;
    else if (x == sum) {
      cout << vec[i].second << ' ' << vec[j].second;
      return 0;
    } else
      --j;
  }
  cout << "IMPOSSIBLE";
}
