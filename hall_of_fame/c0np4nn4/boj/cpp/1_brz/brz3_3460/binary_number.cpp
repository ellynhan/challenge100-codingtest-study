#include <iostream>
// #include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    int n;
    cin >> n;

    // for (int i = 0; i < (int)log2((double)n); i++) {
    // }

    int cnt = 0;
    while (n > 0) {
      if (n % 2 == 1) {
        cout << cnt << ' ';
      }
      cnt++;

      n >>= 1;
    }
    cout << '\n';

    t--;
  }
  return 0;
}
