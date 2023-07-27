#include <iostream>

using namespace std;

int count_a[26];
int count_b[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {

    for (int i = 0; i < 26; i++) {
      count_a[i] = 0;
      count_b[i] = 0;
    }

    string a, b;
    cin >> a;
    cin >> b;

    for (auto c: a) {
      count_a[(int)c - 'a'] += 1;
    }

    for (auto c: b) {
      count_b[(int)c - 'a'] += 1;
    }

    bool is_possible = true;
    for (int i = 0; i < 26; i++) {
      if (count_a[i] != count_b[i]) {
        is_possible = false;

        break;
      }
    }

    if (is_possible) {
      cout << "Possible" << '\n';
    } else {
      cout << "Impossible" << '\n';
    }
  }

  return 0;
}
