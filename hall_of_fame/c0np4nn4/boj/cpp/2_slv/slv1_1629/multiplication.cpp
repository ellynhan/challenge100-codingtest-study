#include <cstdint>
#include <iostream>

using namespace std;

int64_t ans;

int64_t a_power_b(int64_t a, int64_t b, int64_t c) {
  if (b == 0) return 1;
  if (b == 1) return a % c;
  if (b % 2 == 0) {
    int64_t half = a_power_b(a, b / 2, c);
    return (half * half) % c;
  }
  // if (b % 2 == 1) 
    return (a * a_power_b(a, b - 1, c)) % c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64_t a, b, c;
  cin >> a >> b >> c;

  ans = a_power_b(a, b, c);

  cout << ans % c << '\n';
  return 0;
}
