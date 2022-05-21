#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int dp[1001]={ 0, 1, 3 };

int func(int n) {
  if(dp[n]) {
    return dp[n];
  }
  return dp[n]=(func(n-1)%10007+2*func(n-2)%10007)%10007;
}

int main() {
  ioboost;

  int n;
  cin>>n;
  cout<<func(n)<<"\n";
  
  return 0;
}
