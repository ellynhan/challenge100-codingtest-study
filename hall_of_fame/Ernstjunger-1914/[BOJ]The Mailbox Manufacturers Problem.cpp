#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

const int INF=1e9;
int tab[1001][1001][11]={};

int func(int a, int b, int c) {
  if(a==b) {
    return 0;
  }
  if(a>b) {
    exit(1);
  }
  if(c==0) {
    return INF;
  }

  if(tab[a][b][c]==-1) {
    int tmp=INF;

    for(int i=a+1; i<=b; i++) {
      tmp=min(tmp, i+max(func(a, i-1, c-1), func(i, b, c)));
    }
    tab[a][b][c]=tmp;
  }
  return tab[a][b][c];
}

int main() {
  ioboost;
  memset(tab, -1, sizeof(tab));
  
  int a, b, n;
  cin>>n;

  while(n--) {
    cin>>a>>b;
    cout<<func(0, b, a)<<"\n";
  }
  return 0;
}