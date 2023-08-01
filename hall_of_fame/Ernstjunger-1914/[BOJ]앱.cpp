#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int n, m;
int res=1e9;
int bite[101], cost[101];
int dp[101][10001];

int main() {
  ioboost;

  cin>>n>>m;

  for(int i=1; i<=n; i++) cin>>bite[i];
  for(int i=1; i<=n; i++) cin>>cost[i];

  for(int i=1; i<=n; i++) {
    for(int j=0; j<=10000; j++) {
      if(cost[i]<=j) {
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-cost[i]]+bite[i]);
      } else {
        dp[i][j]=dp[i-1][j];
      }

      if(dp[i][j]>=m) res=min(res, j);
    }
  }
  cout<<res<<"\n";
  
  return 0;
}