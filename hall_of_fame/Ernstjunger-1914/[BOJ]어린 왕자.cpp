#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t, dep, ent;
  cin>>t;

  while(t--) {
    int n, x, x1, x2, y, y1, y2, r;
    cin>>x1>>y1>>x2>>y2>>n;
    ent=dep=0;

    while(n--) {
      cin>>x>>y>>r;

      if((x-x1)*(x-x1)+(y-y1)*(y-y1)<r*r) {
        if((x-x2)*(x-x2)+(y-y2)*(y-y2)>r*r) {
          dep++;
        }
      }
      
      if((x-x1)*(x-x1)+(y-y1)*(y-y1)>r*r) {
        if((x-x2)*(x-x2)+(y-y2)*(y-y2)<r*r) {
          ent++;
        }
      }
    }  
    cout<<dep+ent<<"\n";
  }
  return 0;
}