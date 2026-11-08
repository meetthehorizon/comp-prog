#include <bits/stdc++.h>
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> moves = {"1 3"};

  while (--n) {
    int sz = moves.size();
    moves.push_back("1 3");
    for (int i = 0; i < sz; ++i) {
      moves.push_back(moves[i]);
      auto& ref = moves.back();
      replace(ref.begin(), ref.end(), '1', 'x');
      replace(ref.begin(), ref.end(), '2', '1');
      replace(ref.begin(), ref.end(), 'x', '2');

      replace(moves[i].begin(), moves[i].end(), '2', 'x');
      replace(moves[i].begin(), moves[i].end(), '3', '2');
      replace(moves[i].begin(), moves[i].end(), 'x', '3');
    }
  }

  cout << moves.size() << '\n';
  for (auto& s : moves)
    cout << s << '\n';
}
