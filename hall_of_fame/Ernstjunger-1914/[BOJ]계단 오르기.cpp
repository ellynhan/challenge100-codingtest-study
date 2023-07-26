    #include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n;
int dp[301];
int stair[301];

int func(int x) {
  if(x<0) {
    return 0;
  }

  int& ret=dp[x];

  if(ret!=-1) {
    return ret;
  }

  ret=max(ret, func(x-2)+stair[x]);
  ret=max(ret, func(x-3)+stair[x-1]+stair[x]);

  return ret;
}

int main() {
  ioboost;

  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>stair[i];
  }

  memset(dp, -1, sizeof(dp));
  cout<<func(n-1)<<"\n";

  return 0;
}