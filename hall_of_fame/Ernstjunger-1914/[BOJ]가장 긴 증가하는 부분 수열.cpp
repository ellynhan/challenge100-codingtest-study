#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[1005], dp[1005];

int main() {
  ioboost;

  int n, res=0;
  cin>>n;

  for(int i=1; i<=n; i++) cin>>arr[i];

  for(int i=1; i<=n; i++) {
    for(int j=0; j<i; j++) {
      if(arr[i]>arr[j]&&dp[i]<=dp[j]) {
        dp[i]=dp[j]+1;
        if(dp[i]>res) res=dp[i];
      }
    }
  }
  cout<<res<<"\n";
  
  return 0;
}