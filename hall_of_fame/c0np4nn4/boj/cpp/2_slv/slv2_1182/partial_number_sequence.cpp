#include <iostream>

using namespace std;

int n, s;
int ans;

int arr[21];

void func(int c, int b) {
  if (c == n) {
    if (b == s) {
      ans++;
    }
    return;
  }

  func(c + 1, b);
  func(c + 1, b + arr[c]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  func(0, 0);

  if (s == 0) {
    ans--;
  }

  cout << ans << '\n';

  return 0;
}
