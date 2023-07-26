#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t, n, m;
  int a[1000], b[1000];
  ll res=0;
  map<ll, ll> ml;
  cin>>t>>n;

  for(int i=0; i<n; i++) cin>>a[i];
  
  cin>>m;
  for(int i=0; i<m; i++) cin>>b[i];

  for(int i=0; i<n; i++) {
    ll sum=0;

    for(int j=i; j<n; j++) {
      sum+=a[j];
      ml[sum]++;
    }
  }

  for(int i=0; i<m; i++) {
    ll sum=0;

    for(int j=i; j<m; j++) {
      sum+=b[j];
      res+=ml[t-sum];
    }
  }
  cout<<res<<"\n";
  
  return 0;
}