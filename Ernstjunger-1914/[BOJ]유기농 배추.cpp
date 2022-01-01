#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, k;
int field[51][51];
int x[]={ -1, 1, 0, 0 };
int y[]={ 0, 0, 1, -1 };
bool flag[51][51];

void func(int a, int b) {
  flag[a][b]=1;

  for(int i=0; i<4; i++) {
    int xx=a+x[i], yy=b+y[i];

    if(xx>=0&&xx<n&&yy>=0&&yy<m) {
      if(field[xx][yy]) {
        if(!flag[xx][yy]) {
          func(xx, yy);
        }
      }
    } else {
      continue;
    }
  }
}

int main() {
  ioboost;

  int t;
  cin>>t;

  while(t--) {
    int cnt=0;
    cin>>m>>n>>k;

    for(int i=0; i<k; i++) {
      int xx, yy;
      cin>>xx>>yy;
      field[yy][xx]=1;
    }

    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(field[i][j]) {
          if(!flag[i][j]) {
            cnt++;
            func(i, j);
          }
        }
      }
    }
    cout<<cnt<<"\n";
    memset(flag, false, sizeof(flag));
    memset(field, 0, sizeof(field));
  }

  return 0;
}
