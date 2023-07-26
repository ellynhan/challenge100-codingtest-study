#include <iostream>
#include <cmath>

using namespace std;
using ll=long long;

int n;
int r, c;

ll z(int n, int r, int c) {
  // cout << "\nn: " << n << ", r: " << r << ", c: " << c << endl;
  if (n == 1) {
    if (r == 0 && c == 0) return 0;
    if (r == 0 && c == 1) return 1;
    if (r == 1 && c == 0) return 2;
    if (r == 1 && c == 1) return 3;
  }

  ll bound = pow(2, n-1);
  ll p = pow(bound, 2);

  ll res = 0;

  // 1
  if (r < bound && c < bound) {
    // cout << "111!" << endl;
    res = 0 * p + z(n - 1, r % bound, c % bound);
  }

  // 2
  if (r < bound && c >= bound) {
    // cout << "222!" << endl;
    res = 1 * p + z(n - 1, r % bound, c % bound);
  }

  // 3
  if (r >= bound && c < bound) {
    // cout << "333!" << endl;
    res = 2 * p + z(n - 1, r % bound, c % bound);
  }

  // 4
  if (r >= bound && c >= bound) {
    // cout << "444!" << endl;
    res = 3 * p + z(n - 1, r % bound, c % bound);
  }

  // cout << "res: " << res << endl;

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> r >> c;

  cout << z(n, r, c) << endl;
  return 0;
}
