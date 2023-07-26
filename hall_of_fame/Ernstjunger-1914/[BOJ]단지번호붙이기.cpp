#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int dx[]={ 1, -1, 0, 0 };
int dy[]={ 0, 0, 1, -1 };
vector<int> vi;
int n, cnt=0;
string board[26];

void func(int x, int y) {
  for(int i=0; i<4; i++) {
    int xx=x+dx[i];
    int yy=y+dy[i];

    if(xx<0||xx>=n||yy<0||yy>=n) {
      continue;
    }

    if(board[xx][yy]=='1') {
      cnt++;
      board[xx][yy]='2';
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

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(board[i][j]=='1') {
        cnt=1;
        board[i][j]='2';
        func(i, j);
        vi.push_back(cnt);
      }
    }
  }

  cout<<vi.size()<<"\n";
  sort(vi.begin(), vi.end());

  for(int i=0; i<vi.size(); i++) {
    cout<<vi[i]<<"\n";
  }
  return 0;
}