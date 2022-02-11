#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t;
  cin>>t;

  while(t--) {
    bool flag=0;
    int n, m, x, y;
    cin>>m>>n>>x>>y;
    x--; y--;

    for(int i=x; i<(n*m); i+=m) {
      if(i%n==y) {
        flag=1;
        cout<<i+1<<"\n";

        break;
      }
    }

    if(!flag) {
      cout<<-1<<"\n";
    }
  }
  return 0;
}