#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0;
  cin >> n;

  for (int i = 2; i < 10000001; i++) {
    if (n % i == 0) {
      cout << i << endl;

      n = n / i;

      i = 1;

      continue;
    }
  }

  return 0;
}
