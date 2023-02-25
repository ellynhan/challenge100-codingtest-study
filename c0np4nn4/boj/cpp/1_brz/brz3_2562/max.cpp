#include <iostream>

using namespace std;

pair<int, int> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i <= 9; i++) {
    int num;
    cin >> num;

    if (ans.first < num) {
      ans.first = num;
      ans.second = i;
    }
  }

  cout << ans.first << '\n' << ans.second << '\n';
  return 0;
}
