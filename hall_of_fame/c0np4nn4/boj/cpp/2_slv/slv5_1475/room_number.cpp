#include <cmath>
#include <iostream>

using namespace std;

int count[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int num = 0;
  cin >> num;

  while (num > 0) {
    count[num % 10] += 1;
    num /= 10;
  }

  int max = 0;
  for (int i = 0; i < 10; i++) {
    if (i != 6 && i != 9) {
      if (max < count[i]) {
        max = count[i];
      }
    }
  }

  if (max * 2 <= (count[6] + count[9])) {
    max = ceil((float)(count[6] + count[9]) / 2);
  }

  cout << max << '\n';

  return 0;
}
