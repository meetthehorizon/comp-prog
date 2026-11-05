#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  map<char, int> a;
  for (auto c : s)
    a[c]++;

  char o = 0;
  for (auto& [k, v] : a) {
    if (v & 1) {
      if (o) {
        cout << "NO SOLUTION";
        return 0;
      }
      o = k;
    }
  }

  string half = "";
  for (auto& [k, v] : a) {
    half += string(v / 2, k);
  }
  cout << half;
  if (o)
    cout << o;

  reverse(half.begin(), half.end());
  cout << half;
}
