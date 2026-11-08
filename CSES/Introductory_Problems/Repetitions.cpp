#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int ans = 1, curr = 1;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1])
      ans = max(ans, ++curr);
    else {
      curr = 1;
    }
  }
  cout << ans << '\n';
}
