#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int dp[1001][3];

int main() {
  ioboost;

  int n, res=0;
  cin>>n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<3; j++) {
      cin>>dp[i][j];
    }
  }

  for(int i=1; i<n; i++) {
    dp[i][0]+=min(dp[i-1][1], dp[i-1][2]);
    dp[i][1]+=min(dp[i-1][0], dp[i-1][2]);
    dp[i][2]+=min(dp[i-1][0], dp[i-1][1]);
  }
  res=min({ dp[n-1][0], dp[n-1][1], dp[n-1][2] });
  cout<<res<<"\n";
  
  return 0;
}