#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

ll n;
ll histo[100010];

int main() {
  ioboost;

  while(1) {
    cin>>n;
    if(n==0) break;

    for(int i=0; i<n; i++) cin>>histo[i];
    histo[n]=-1;

    ll ans=0;
    stack<int> si;
    
    for(int i=0; i<=n; i++) {
      while(!si.empty()&&histo[i]<histo[si.top()]) {
        int h, w;
        h=si.top();
        si.pop();

        if(si.empty()) w=i;
        else w=i-si.top()-1;

        ans=max(ans, histo[h]*w);
      }
      si.push(i);
    }
    cout<<ans<<"\n";
  }
  return 0;
}