#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;

  sort(s.begin(), s.end());
  vector<string> perm;

  do {
    perm.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << perm.size() << '\n';
  for (auto& x : perm)
    cout << x << endl;
}
