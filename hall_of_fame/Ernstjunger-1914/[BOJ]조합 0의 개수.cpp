#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

pair<ll, ll> func(ll n) {
  ll cnt2=0, cnt5=0;

  for(ll i=2; i<=n; i*=2) cnt2+=n/i;
  for(ll i=5; i<=n; i*=5) cnt5+=n/i;

  return { cnt2, cnt5 };
}

int main() {
  ioboost;

  ll n, m;
  pair<ll, ll> resn, resm, res;
  cin>>n>>m;

  resn=func(n);
  resm=func(m);
  res=func(n-m);

  cout<<min(resn.first-resm.first-res.first, resn.second-resm.second-res.second)<<"\n";
  
  return 0;
}