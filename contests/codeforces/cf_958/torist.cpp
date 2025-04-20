/**
 *    author:  tourist
 *    created: 15.07.2024 23:39:11
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    vector<int> bits;
    for (int i = 0; i < 62; i++) {
      if (n & (int64_t(1) << i)) {
        bits.push_back(i);
      }
    }
    int k = int(bits.size());
    if (k == 1) {
      cout << 1 << '\n';
      cout << n << '\n';
    } else {
      cout << k + 1 << '\n';
      for (int i = k - 1; i >= 0; i--) {
        cout << n - (int64_t(1) << bits[i]) << " ";
      }
      cout << n << '\n';
    }
  }
  return 0;
}

//999999999999999898