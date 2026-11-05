#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<string> vec = {"0", "1"};

  while (--n) {
    int x = vec.size();
    for (int i = x - 1; i >= 0; --i) {
      vec.push_back("1" + vec[i]);
      vec[i] = "0" + vec[i];
    }
  }

  for (auto& v : vec) {
    cout << v << '\n';
  }
}
