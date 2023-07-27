#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n, m, _max;
bool flag[500][500]={};
int board[500][500]={};
int ax[]={ 0, 0, -1, 1 };
int ay[]={ -1, 1, 0, 0 };

void check_block(int x, int y) {
  if(x+1<n&&y+2<m) {
    _max=max(_max, board[x][y]+board[x][y+1]+board[x][y+2]+board[x+1][y+1]);
  }

  if(x+2<n&&y+1<m) {
    _max=max(_max, board[x][y]+board[x+1][y]+board[x+1][y+1]+board[x+2][y]);
  }

  if(x-1>=0&&y+2<m) {
    _max=max(_max, board[x][y]+board[x][y+1]+board[x][y+2]+board[x-1][y+1]);
  }

  if(x+2<n&&y-1>=0) {
    _max=max(_max, board[x][y]+board[x+1][y]+board[x+1][y-1]+board[x+2][y]);
  }
}

void other_block(int l, int sum, int x, int y) {
  if(l==3) {
    _max=max(_max, sum);

    return;
  }

  for(int i=0; i<4; i++) {
    int xx=x+ax[i], yy=y+ay[i];

    if(xx<0||yy<0||xx>=n||yy>=m) {
      continue;
    }

    if(flag[xx][yy]) {
      continue;
    }

    flag[xx][yy]=1;
    other_block(l+1, sum+board[xx][yy], xx, yy);
    flag[xx][yy]=0;
  }
}

void findmaxvalue(int x, int y) {
  check_block(x, y);
  flag[x][y]=1;
  other_block(0, board[x][y], x, y);
  flag[x][y]=0;
}

int main() {
  ioboost;

  cin>>n>>m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>board[i][j];
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      findmaxvalue(i, j);
    }
  }
  cout<<_max<<"\n";

  return 0;
}