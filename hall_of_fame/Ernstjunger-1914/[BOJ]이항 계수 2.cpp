#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

ll dp[1001][1001];

int main() {
  ioboost;

  int n, k;
  cin>>n>>k;

  dp[0][0]=dp[1][0]=dp[1][1]=1;

  for(int i=2; i<=n; i++) {
    for(int j=0; j<=i; j++) {
      if(j==0) {
        dp[i][0]=1;
      } else if(j==i) {
        dp[i][j]=1;
      } else {
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
      }
    }
  }
  cout<<dp[n][k]<<"\n";
  
  return 0;
}