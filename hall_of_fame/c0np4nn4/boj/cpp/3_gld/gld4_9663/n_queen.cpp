#include <iostream>

using namespace std;

int n;
int ans;

bool issue1[30];  // columns
bool issue2[30];  // right-up line
bool issue3[30];  // right-down line

void func(int x) {
  if (x == n) {
    ans++;
    return;
  }

  for (int y = 0; y < n; y++) {
    if (issue1[y] || issue2[x + y] || issue3[x - y + n + 1]) continue;
    issue1[y] = true;
    issue2[x + y] = true;
    issue3[x - y + n + 1] = true;

    func(x + 1);

    issue1[y] = false;
    issue2[x + y] = false;
    issue3[x - y + n + 1] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  func(0);

  cout << ans << '\n';
  return 0;
}
