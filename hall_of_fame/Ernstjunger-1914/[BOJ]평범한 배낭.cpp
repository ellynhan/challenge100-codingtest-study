#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int dp[101][100001]={};
int w[101], v[101];

int main() {
  ioboost;

  int n, k;
  cin>>n>>k;

  for(int i=1; i<=n; i++) cin>>w[i]>>v[i];

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=k; j++) {
      if(j-w[i]>=0) {
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
      } else {
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  cout<<dp[n][k]<<"\n";
  
  return 0;
}