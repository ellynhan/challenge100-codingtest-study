#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, cnt=0, tmp;

  while(1) {
    cnt=0;
    cin>>n;

    if(n==0) {
      break;
    }

    for(int i=n+1; i<=n*2; i++) {
      tmp=sqrt(i);

      if(tmp==1&&i!=1) {
        cnt++;
        continue;
      }

      if(i%2) {
        for(int j=2; j<=tmp; j++) {
          if(!(i%j)) {
            break;
          }
          if(j==tmp) {
            cnt++;
          }
        }
      }
    }
    cout<<cnt<<"\n";
  }
  return 0;
}