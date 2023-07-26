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

  bool b = true;
  while (dummy.size() != 1) {
    if (b == true) {
      dummy.pop();
      b = false;
    }

    else {
      int tmp = dummy.front();
      dummy.push(tmp);
      dummy.pop();
      b = true;
    }
  }

  cout << dummy.front() << '\n';
  return 0;
}
