#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool vis[10];
vector<int> nums;

void func(int k, int idx) {
  if (k == m) {
    for (int i = 1; i <= m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;

    arr[k + 1] = nums[i];

    vis[i] = true;

    func(k + 1, i);

    vis[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  nums.push_back(0);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    nums.push_back(tmp);
  }

  for (int i = 0; i <= n; i++) {
    vis[i] = false;
  }

  sort(nums.begin(), nums.end());

  func(0, 0);

  return 0;
}
