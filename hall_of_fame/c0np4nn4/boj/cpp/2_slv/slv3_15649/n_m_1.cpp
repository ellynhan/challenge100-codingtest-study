#include <iostream>

using namespace std;

int n, m;

int arr[8];
bool vis[8];

// k: current size of the arr
void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      arr[k] = i;
      vis[i] = true;
      func(k + 1);
      vis[i] = false;
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
