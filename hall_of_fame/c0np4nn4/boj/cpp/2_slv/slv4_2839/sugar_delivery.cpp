#include <cstdint>
#include <iostream>

using namespace std;

bool check(int weight) {
  bool res = false;
  for (int i = 0; i <= 1000 && (weight - i * 5) >= 0; i++) {
    if ((weight - i * 5) % 3 == 0) {
      res = true;
      break;
    }
  }
  return res;
}

int get_minimum_count(int weight) {
  int count = 2000; // cond' 5000 >= N

  for (int i = 0; i <= 1000 && (weight - i * 5) >= 0; i++) {
    if ((weight - i * 5) % 3 == 0) {
      if (i + (weight - i * 5) / 3 < count) {
        count = i + (weight - i * 5) / 3;

        // cout << "[!] 3:" << (weight - i * 5) / 3 << ", 5:" << i << endl;
      }
    }
  }

  return count;
}

int main() {
  int weight = 0;
  cin >> weight;

  if (check(weight) == false) {
    cout << -1 << endl;
  } else {
    cout << get_minimum_count(weight) << endl;
  }
  return 0;
}
