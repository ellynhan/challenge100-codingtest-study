// ref: https://iridescent-zeal.tistory.com/61?category=1261302

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
int n; // "Mersenne Number"
int arr[1024];
vector<int> tree[10];

void fill_out(int s, int e, int d) {
  // cout << "\n[-] fill_out, s: " << s << ", e: " << e << ", d: " << d << endl;
  if (d >= k) return;

  if (s == e) {
    tree[d].push_back(arr[s]);
    // cout << "[2] push, v: " << arr[s] << endl;
    return;
  }

  int m = (s + e) / 2;

  if (m < 0 || m >= n) return;

  // cout << "[1] push, v: " << arr[m] << endl;
  tree[d].push_back(arr[m]);

  // cout << "[-] Left subtree" << endl;
  fill_out(s, m - 1, d + 1);

  // cout << "[-] Right subtree" << endl;
  fill_out(m + 1, e, d + 1);
}

int main() {
  cin >> k;

  n = pow(2, k) - 1;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  fill_out(0, n - 1, 0);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < tree[i].size(); j++) {
      cout << tree[i][j] << ' ';
    }
    cout << endl;
  }

  
  return 0;
}
