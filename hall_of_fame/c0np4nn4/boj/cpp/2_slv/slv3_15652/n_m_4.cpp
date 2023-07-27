#include <iostream>

using namespace std;

int n, m;
int arr[9];

void func(int k) {
  if (k == m) {
    for (int i = 1; i <= m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (arr[k] <= i) {
      arr[k + 1] = i;
      func(k + 1);
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
