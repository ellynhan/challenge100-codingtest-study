#include <iostream>

using namespace std;

int get_self_num(int a) {
  int res = a;

  while (a > 0) {
    res += (a % 10);

    a /= 10;
  }

  return res;
}

int main() {
  int num_table[10001];

  for (int i = 0; i < 10001; i++) {
    num_table[i] = i;
  }

  for (int i = 1; i < 10001; i++) {
    int t = i;

    if (num_table[t] == -1)
      continue;

    while (get_self_num(t) < 10000) {
      t = get_self_num(t);

      num_table[t] = -1;
    }
  }

  for (int i = 1; i < 10000; i++) {
    if (num_table[i] != -1) {
      cout << num_table[i] << endl;
    }
  }

  return 0;
}
