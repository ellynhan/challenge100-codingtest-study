#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n, ans=1e9;
int state[21][21];
bool flag[22];

void func(int x, int p) {
  if(x==n/2) {
    int s=0, l=0;

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if(flag[i]==true&&flag[j]==true) s+=state[i][j];
        if(flag[i]==false&&flag[j]==false) l+=state[i][j];
      }
    }

    int tmp=abs(s-l);
    if(ans>tmp) ans=tmp;
    
    return;
  }

  for(int i=p; i<n; i++) {
    flag[i]=true;
    func(x+1, i+1);
    flag[i]=false;
  }
}

int main() {
  ioboost;

  cin>>n;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>state[i][j];
    }
  }

  func(0, 1);
  cout<<ans<<"\n";
  
  return 0;
}