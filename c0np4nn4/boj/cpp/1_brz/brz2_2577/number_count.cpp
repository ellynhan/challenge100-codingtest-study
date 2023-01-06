#include <iostream>

using namespace std;

int count[10];

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int d = a * b * c;

  while (d > 0) {
    count[d % 10] += 1;
    d /= 10;
  }

  for (int i = 0; i < 10; i++) {
    cout << count[i] << '\n';
  }
  return 0;
}
