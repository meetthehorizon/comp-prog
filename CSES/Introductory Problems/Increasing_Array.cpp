#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  long long ans = 0;
  while (--n) {
    int y;
    cin >> y;
    ans += max(0, max(x, y) - y);
    x = max(x, y);
  }

  cout << ans << '\n';
}
