#include <bits/stdc++.h>
#include <cassert>
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

int num_digits(unsigned long long x) {
  return x ? 1 + num_digits(x / 10) : 0;
}

unsigned long long digits_before(unsigned long long x) {
  int d = num_digits(x);

  unsigned long long r = 1;
  for (int i = 1; i < d; ++i)
    r = r * 10;

  r = d * (x - r) + ((9 * (d - 1) - 1) * r + 1) / 9;

  return r;
}

void solve() {
  unsigned long long n;

  cin >> n;
  unsigned long long x = 0, j = 1LL << 60;

  while (j) {
    do {
      if (digits_before(x + j) < n)
        x += j;
      else
        break;
    } while (true);
    j >>= 1;
  }

  cout << to_string(x)[n - digits_before(x) - 1] << '\n';
}
