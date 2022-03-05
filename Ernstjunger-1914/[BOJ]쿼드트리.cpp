#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef size_t st;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

int board[64][64];

int func(int n, int y, int x) {
  if(n==1) {
    cout<<board[y][x];

    return 0;
  }

  int hal=n/2, find=board[y][x];

  for(int i=y; i<n+y; i++) {
    for(int j=x; j<n+x; j++) {
      if(find!=board[i][j]) {
        cout<<"(";
        func(hal, y, x);
        func(hal, y, x+hal);
        func(hal, y+hal, x);
        func(hal, y+hal, x+hal);
        cout<<")";

        return 0;
      }
    }
  }
  cout<<find;

  return 0;
}

int main() {
  ioboost;

  int n;
  string str;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>str;

    for(int j=0; j<n; j++) {
      board[i][j]=str[j]-'0';
    }
  }
  func(n, 0, 0);

  return 0;
}