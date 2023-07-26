#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, m;
  int a[101], dp[10001]={};
  cin>>n>>m;

  for(int i=0; i<n; i++) cin>>a[i];
  dp[0]=1;

  for(int i=0; i<n; i++) {
    for(int j=a[i]; j<=m; j++) {
      if(dp[j-a[i]]) dp[j]+=dp[j-a[i]];
    }
  }
  cout<<dp[m]<<"\n";
  
  return 0;
}