#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n, m;
int board[100][100];
int move_leng[100][100];
bool flag[100][100];
int dx[]={ 0, 0, 1, -1 };
int dy[]={ 1, -1, 0, 0 };

void func(int x, int y) {
  queue<pair<int, int>> qp;
  qp.push(make_pair(y, x));

  move_leng[y][x]=1; flag[y][x]=1;

  while(!qp.empty()) {
    int y=qp.front().first, x=qp.front().second;
    qp.pop();

    for(int i=0; i<4; i++) {
      int xx=x+dx[i], yy=y+dy[i];

      if(xx>=0&&xx<m&&yy>=0&&yy<n&&board[yy][xx]==1&&!flag[yy][xx]) {
        move_leng[yy][xx]=move_leng[y][x]+1;
        flag[yy][xx]=1;
        qp.push(make_pair(yy, xx));
      }
    }
  }
}

int main() {
  cin>>n>>m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%1d", &board[i][j]);
    }
  }

  func(0, 0);
  cout<<move_leng[n-1][m-1]<<"\n";

  return 0;
}