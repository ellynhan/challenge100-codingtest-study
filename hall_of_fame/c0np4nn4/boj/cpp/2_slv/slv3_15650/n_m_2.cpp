#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool issue[9];

void func(int k) {
  if (k == m) {
    for (int i = 1; i <= m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (issue[i] == true) {
      continue;
    } else {
      if (arr[k] < i) {
        arr[k + 1] = i;
        issue[i] = true;
        func(k + 1);
        issue[i] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  func(0);

  return 0;
}
