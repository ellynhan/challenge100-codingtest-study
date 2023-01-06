#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> val;

int main() {
  int n;
  cin >> n;

  dp.resize(n + 1);
  val.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  fill(dp.begin(), dp.end(), 1);

  // dp
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (val[i] > val[j]) {
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  // check
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i] << ' ';
  // }
  // cout << endl;
  //

  // max
  auto it = max_element(begin(dp), end(dp));

  cout << *it << endl;

  return 0;
}
