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
  long long ans = vec[0], sum = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, sum += vec[i]);
    if (sum < 0)
      sum = 0;
  }

  cout << ans;
}
