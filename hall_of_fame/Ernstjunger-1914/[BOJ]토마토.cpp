#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int adj[1001][1001];
int tomato[1001][1001];
int x[]={ 0, -1, 0, 1 };
int y[]={ -1, 0, 1, 0 };

int main() {
  ioboost;

  int n, m, result=0;
  queue<pair<int, int>> qp;
  cin>>m>>n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>adj[i][j];
      tomato[i][j]=-1;

      if(adj[i][j]==1) {
        qp.push(make_pair(i, j));
        tomato[i][j]=0;
      }
    }
  }

  while(!qp.empty()) {
    int a=qp.front().first, b=qp.front().second;
    qp.pop();

    for(int i=0; i<4; i++) {
      int xx=a+x[i], yy=b+y[i];

      if(xx>=0&&xx<n&&yy>=0&&yy<m) {
        if(tomato[xx][yy]==-1&&adj[xx][yy]==0) {
          tomato[xx][yy]=tomato[a][b]+1;
          qp.push(make_pair(xx, yy));
        }
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      result=max(tomato[i][j], result);
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tomato[i][j]==-1&&adj[i][j]==0) {
        result=-1;
      }
    }
  }
  cout<<result<<"\n";

  return 0;
}