#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int main() {
  int n;
  cin >> n;

  dp.resize(n + 1);

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  // dp[4] = 5;

  for (int i = 4; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  // check 
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i] << endl;
  // }

  cout << dp[n] << endl;

  return 0;
}
