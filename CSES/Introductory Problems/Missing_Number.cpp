#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x = n;

  for (int i = 1; i < n; i++) {
    int y;
    cin >> y;
    x += i - y;
  }
  cout << x << '\n';
}
