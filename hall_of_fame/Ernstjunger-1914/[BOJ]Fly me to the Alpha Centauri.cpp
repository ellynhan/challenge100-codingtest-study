#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t;
  cin>>t;

  while(t--) {
    ll a, x, y;
    cin>>x>>y;
    a=(int)sqrt(y-x);

    if((y-x)==a*a) cout<<a*2-1<<"\n";
    else if((y-x)>a*a&&(y-x)<=a*a+a) cout<<a*2<<"\n";
    else if((y-x)>a*a+a&&(y-x)<(a+1)*(a+1)) cout<<a*2+1<<"\n";
  }
  return 0;
}