#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    // Combination: n! / (r! * (n-r)!)
    int r;
    int n;
    cin >> r >> n;

    int res = 1;

    int denom = 1;

    for (int i = (r + 1); i <= n; i++) {
      // cout << "[-] i: " << i << ", denom: " << denom << endl;
      res *= i;
      res /= denom++;
    }

    cout << res << endl;

    t--;
  }

  return 0;
}
