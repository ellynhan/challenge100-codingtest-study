#include <iostream>

using namespace std;

int sum;

int main() {
  for (int i = 0; i < 5; i++) {
    int a;
    cin >> a;

    int b = (a * a) % 10;

    sum += b;
  }

  cout << sum % 10 << '\n';
  return 0;
}
