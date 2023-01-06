#include <iostream>
#include <queue>

using namespace std;

queue<int> dummy;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    dummy.push(i);
  }

  bool turn = true;
  while (dummy.size() != 1) {
    if (turn == true) {
      cout << dummy.front() << ' ';
      dummy.pop();
      turn = !turn;
    }

    else {
      dummy.push(dummy.front());
      dummy.pop();
      turn = !turn;
    }
  }

  cout << dummy.front() << '\n';

  return 0;
}
