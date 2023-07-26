#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

ll func(ll x) {
  ll a=x, b=1, cnt=0;

  while(a) {
    cnt+=(x+1)/(b<<1)*b;

    if(a&1) cnt+=(x+1)%b;
    a>>=1; b<<=1;
  }
  return cnt;
}

int main() {
  ioboost;

  ll a, b;
  cin>>a>>b;
  cout<<func(b)-func(a-1)<<"\n";
  
  return 0;
}