#include <bits/stdc++.h>
using namespace std;

void rotate(char& x) {
  if (++x == 'E')
    x = 'A';
}

bool poss(map<char, int>& freq) {
  int tot = 0, mx = 0;
  for (auto& [c, v] : freq) {
    tot += v;
    mx = max(mx, v);
  }
  return ((tot + 1) / 2) >= mx;
}

bool is_poss(int freq[26]) {
  int tot = accumulate(freq, freq + 26, 0);
  int max = *max_element(freq, freq + 26);

  return (tot + 1) / 2 >= max;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();
  int freq[26]{};
  for (auto& c : s) {
    freq[c - 'A']++;
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    bool any = false;
    for (int j = 0; j < 26; ++j)
      if (freq[j] && (ans.empty() || ans.back() != (j + 'A'))) {
        freq[j]--;
        if (is_poss(freq)) {
          ans.push_back(j + 'A');
          any = true;
          break;
        }
        freq[j]++;
      }
    if (!any) {
      cout << "-1\n";
      return 0;
    }
  }

  cout << ans << '\n';
}
