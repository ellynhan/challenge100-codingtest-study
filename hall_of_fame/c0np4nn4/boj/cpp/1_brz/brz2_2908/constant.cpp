#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int r_n = 0;
  int r_m = 0;

  while (n > 0) {
    r_n *= 10;
    r_n += (n % 10);
    n /= 10;
  }

  while (m) {
    r_m *= 10;
    r_m += (m % 10);
    m /= 10;
  }

  if (r_n <= r_m) {
    cout << r_m << '\n';
  } else {
    cout << r_n << '\n';
  }

  return 0;
}
