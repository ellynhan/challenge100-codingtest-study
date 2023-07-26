#include <iostream>

using namespace std;
using ll=long long;

ll dp[41] = {0, 1};

ll fibo(int n) {
  if (n == 0) {
    return dp[0];
  } else if (n == 1) {
    return dp[1];
  } else if (dp[n] == 0) {
    dp[n] = fibo(n - 2) + fibo(n - 1);
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n == 0) {
      cout << "1 0\n";
    } else {
      cout << fibo(n - 1) << ' ' << fibo(n) << '\n';
    }
  }

  return 0;
}
