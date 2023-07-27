#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000

using namespace std;
using ll=long long;

int n;
int dx[]={ 1, -1, 0, 0 };
int dy[]={ 0, 0, 1, -1 };
int flag[101][101];
string board[101];

void func(int x, int y) {
  for(int i=0; i<4; i++) {
    int xx=x+dx[i], yy=y+dy[i];

    if(xx<0||xx>=n||yy<0||yy>=n) {
      continue;
    }

    if(!flag[xx][yy]&&board[xx][yy] == board[x][y]) {
      flag[xx][yy]=1;
      func(xx, yy);
    }
  }
}

int main() {
  ioboost;

  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>board[i];
  }

  int cntn=0, cnta=0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!flag[i][j]) {
        cntn++;
        flag[i][j]=1;
        func(i, j);
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(board[i][j]=='G') {
        board[i][j]='R';
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      flag[i][j]=0;
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!flag[i][j]) {
        cnta++;
        flag[i][j]=1;
        func(i, j);
      }
    }
  }
  cout<<cntn<<" "<<cnta<<"\n";

  return 0;
}