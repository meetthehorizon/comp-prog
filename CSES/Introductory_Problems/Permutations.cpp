#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  if (n == 1)
    cout << "1";
  else if (n < 4)
    cout << "NO SOLUTION";
  else if (n == 4)
    cout << "3 1 4 2";
  else {
    for (int x = ((n >> 1) << 1); x > 0; x -= 2)
      cout << x << ' ';
    for (int x = n - ((n & 1) == 0); x > 0; x -= 2)
      cout << x << ' ';
  }
}
