// 34분

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> val;
vector<int> dp;

int ll = 0;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  val.resize(n + 1);
  dp.resize(n + 1);

  fill(dp.begin(), dp.end(), 1);

  // val[0] = 0;
  // dp[0] = 0;

  dp[1] = 1;

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }


  // i == curr
  for (int i = 2; i <= n; i++) {

    // `j` for iteration
    for (int j = 1; j <= i; j++) {

      // val[curr] should be smaller than val[j]
      if (val[i] < val[j]) {

        // get the longest length
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  // for check
  // cout << "[!] dp array" << endl;
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i] << ' ';
  // }
  // cout << endl << endl;

  for (int i = 1; i <= n; i++) {
    if (ll < dp[i]) {
      ll = dp[i];
    }
  }

  cout << ll << endl;

  return 0;
}
