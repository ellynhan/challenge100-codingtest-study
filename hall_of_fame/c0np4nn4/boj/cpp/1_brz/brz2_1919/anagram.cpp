#include <iostream>
#include <string>

using namespace std;

int count_a[26];
int count_b[26];

int count = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  for (auto c: a) {
    count_a[(int)c - 'a'] += 1;
  }

  for (auto c: b) {
    count_b[(int)c - 'a'] += 1;
  }

  for (int i = 0; i < 26; i++) {
    int tmp = count_a[i] - count_b[i];

    if (tmp < 0) {
      tmp *= -1;
    }

    count += tmp;
  }

  cout << count << '\n';

  return 0;
}
