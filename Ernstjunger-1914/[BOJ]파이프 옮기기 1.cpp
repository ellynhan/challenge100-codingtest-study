#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int n, res;
int board[17][17];
int dx[]={ 0, 1, 1 }, dy[]={ 1, 1, 0 };

struct dire {
  int x, y, d;
};

queue<dire> qd;

void func(int x, int y, int d, int tmp) {
  int xx=x+dx[tmp], yy=y+dy[tmp];

  if(board[xx][yy]==0&&xx>0&&xx<=n&&yy>0&&yy<=n) {
    if(tmp==1) {
      if(board[xx-1][yy]==1||board[xx][yy-1]==1) {
        return;
      }
    }
    qd.push({ xx, yy, tmp });
  }
}

int main() {
  ioboost;

  cin>>n;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>board[i][j];
    }
  }

  qd.push({ 1, 2, 0 });

  while(!qd.empty()) {
    int x=qd.front().x, y=qd.front().y, d=qd.front().d;
    qd.pop();

    if(x==n&&y==n) {
      res++;
    }

    if(d==0) {
      for(int i=0; i<2; i++) {
        func(x, y, d, i);
      }
    } else if(d==1) {
      for(int i=0; i<3; i++) {
        func(x, y, d, i);
      }
    } else {
      for(int i=1; i<3; i++) {
        func(x, y, d, i);
      }
    }
  }
  cout<<res<<"\n";
  
  return 0;
}