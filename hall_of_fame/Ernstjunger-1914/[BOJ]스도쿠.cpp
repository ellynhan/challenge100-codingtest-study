#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n=0;
int sdk[9][9], mark[81][2];

int func(int k) {
  int x=mark[k][0], y=mark[k][1];
  int sx=x/3*3, sy=y/3*3, res=0;
  int flag[10]={};
  
  if(k==n) {
    return 1;
  }

  for(int i=0; i<9; i++) {
    flag[sdk[x][i]]=1; flag[sdk[i][y]]=1;
  }

  for(int i=sx; i<sx+3; i++) {
    for(int j=sy; j<sy+3; j++) {
      flag[sdk[i][j]]=1;
    }
  }

  for(int i=1; i<=9; i++) {
    if(flag[i]==0) {
      sdk[x][y]=i;
      res=func(k+1);

      if(res==1) {
        break;
      }
      sdk[x][y]=0;
    }
  }
  return res;
}

int main() {
  ioboost;

  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cin>>sdk[i][j];

      if(sdk[i][j]==0) {
        mark[n][0]=i; mark[n][1]=j;
        n++;
      }
    }
  }

  func(0);

  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      cout<<sdk[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}