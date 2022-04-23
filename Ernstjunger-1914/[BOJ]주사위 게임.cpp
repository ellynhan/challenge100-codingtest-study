#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, big=0;
  cin>>n;

  for(int i=0; i<n; i++) {
    int x, y, z, mx=0, res=0;
    int prize[1001];
    cin>>x>>y>>z;

    if(x==y&&y==z&&z==x) {
      prize[i]=10000+x*1000;
    } else if(x==y||x==z) {
      prize[i]=1000+x*100;
    } else if(y==z) {
      prize[i]=1000+z*100;
    } else {
      if(x>y&&x>z) {
        mx=x;
      } else if(y>x&&y>z) {
        mx=y;
      } else if(z>x&&z>y) {
        mx=z;
      }
      prize[i]=mx*100;
    }
    if(prize[i]>big) {
      big=prize[i];
    }
  }
  cout<<big<<"\n";
  
  return 0;
}