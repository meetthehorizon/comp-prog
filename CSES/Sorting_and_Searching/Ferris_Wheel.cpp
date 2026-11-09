#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<int> vec(n);
  for (auto& v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());

  int ans = 0;
  for (int i = 0, j = vec.size() - 1; i <= j;) {
    if (vec[i] + vec[j] <= x)
      i++;
    ++ans, --j;
  }

  cout << ans;
}
