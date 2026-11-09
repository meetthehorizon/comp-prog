#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  multiset<int> ms;
  while (n--) {
    int x;
    cin >> x;
    ms.insert(x);
  }
  while (m--) {
    int x;
    cin >> x;
    auto itr = ms.upper_bound(x);
    if (itr != ms.begin()) {
      if (*(--itr) <= x) {
        cout << *itr << '\n';
        ms.erase(itr);
      }
    } else
      cout << "-1\n";
  }
}
