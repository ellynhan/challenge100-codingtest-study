#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, value, miv, mav;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>value;

    if(!i) {
      mav=miv=value;
      continue;
    }
    value<miv&&(miv=value);
    value>mav&&(mav=value);
  }
  cout<<mav*miv<<"\n";
  
  return 0;
}