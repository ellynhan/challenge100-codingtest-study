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

  for (int i = idx; i < n; i++) {
    if (vis[i])
      continue;

    vis[i] = true;

    // if (arr[k] > nums[i])
    //   continue;

    arr[k + 1] = nums[i];

    func(k + 1, i);

    vis[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    nums.push_back(val);
  }

  for (int i = 0; i < n; i++) {
    vis[i] = false;
  }

  sort(nums.begin(), nums.end());

  func(0, 0);

  return 0;
}
