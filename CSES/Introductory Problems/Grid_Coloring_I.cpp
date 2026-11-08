#include <bits/stdc++.h>
using namespace std;

void rotate(char& x) {
  if (++x == 'E')
    x = 'A';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<string> vec(n);
  for (auto& v : vec)
    cin >> v;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      do {
        rotate(vec[i][j]);

        if (i && vec[i - 1][j] == vec[i][j])
          continue;
        if (j && vec[i][j - 1] == vec[i][j])
          continue;
        break;
      } while (1);
    }
  }

  for (auto& v : vec) {
    cout << v << '\n';
  }
}
