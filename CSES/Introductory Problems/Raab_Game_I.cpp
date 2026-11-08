#include <bits/stdc++.h>
using namespace std;

void solve();

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

void solve() {
  int num_rounds, player_one_score, player_two_score;
  cin >> num_rounds >> player_one_score >> player_two_score;

  // all draw case
  if (player_one_score == 0 && player_two_score == 0) {
    cout << "YES\n";
    for (int i = 1; i <= num_rounds; i++) {
      cout << i << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= num_rounds; i++) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }

  if (player_one_score == 0 || player_two_score == 0
      || player_one_score + player_two_score > num_rounds) {
    cout << "NO\n";
    return;
  }

  // get out draw cases earlier
  vector<int> player_one_moves, player_two_moves;
  for (int i = 0; i < num_rounds - (player_one_score + player_two_score); ++i) {
    player_one_moves.push_back(num_rounds - i);
    player_two_moves.push_back(num_rounds - i);
  }
  num_rounds = player_one_score + player_two_score;

  for (int i = 0; i < player_one_score; ++i) {
    player_one_moves.push_back(num_rounds - i);
    player_two_moves.push_back(player_one_score - i);
  }
  for (int i = 0; i < player_two_score; ++i) {
    player_two_moves.push_back(num_rounds - i);
    player_one_moves.push_back(player_two_score - i);
  }

  cout << "YES\n";
  for (auto& v : player_one_moves) {
    cout << v << ' ';
  }
  cout << '\n';

  for (auto& v : player_two_moves) {
    cout << v << ' ';
  }
  cout << '\n';
}
