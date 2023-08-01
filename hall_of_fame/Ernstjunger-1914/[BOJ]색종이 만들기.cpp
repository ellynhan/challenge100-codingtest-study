#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int color_paper[128][128];
int n, b, w;

void func(int x, int y, int sz) {
  int flag=color_paper[x][y];

  for(int i=x; i<x+sz; i++) {
    for(int j=y; j<y+sz; j++) {
      if(color_paper[i][j]==1&&flag==0) {
        flag=2;
      } else if(color_paper[i][j]==0&&flag==1) {
        flag=2;
      }

      if(flag==2) {
        func(x, y, sz/2);
        func(x, y+sz/2, sz/2);
        func(x+sz/2, y, sz/2);
        func(x+sz/2, y+sz/2, sz/2);

        return;
      }
    }
  }

  if(flag==0) {
    w++;
  } else {
    b++;
  }
}

int main() {
  ioboost;

  cin>>n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>color_paper[i][j];
    }
  }

  func(0, 0, n);
  cout<<w<<"\n"<<b<<"\n";

  return 0;
}