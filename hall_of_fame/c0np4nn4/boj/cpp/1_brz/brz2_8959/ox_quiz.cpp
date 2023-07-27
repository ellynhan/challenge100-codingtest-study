#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    string line;
    cin >> line;

    int score = 0;
    int ans = 0;
    for (auto c : line) {
      if (c == 'X') {
        score = 0;
      }
      if (c == 'O') {
        score += 1;
      }
      ans += score;
    }

    cout << ans << '\n';
  }
  return 0;
}
