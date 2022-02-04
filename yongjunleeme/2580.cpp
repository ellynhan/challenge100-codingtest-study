#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int cnt = 0;
int board[9][9];
vector<pair<int, int>> v;
bool flag = false;

bool check(int x, int y){
  for(int i = 0; i < 9; i++){
    if(board[x][y] == board[i][y] && i != x) return false;
    if(board[x][y] == board[x][i] && i != y) return false;
  }
  int xx = x/3;
  int yy = y/3;

  for(int i = xx*3; i < xx*3+3; i++)
    for(int j = yy*3; j < yy*3+3; j++)
      if(board[x][y] == board[i][j] && x != i && y != j) return false;

  return true;
}

void func(int k){
  if(k == cnt){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
    flag = true;
    return;
  }

  int x = v[k].X;
  int y = v[k].Y;
  for(int i = 1; i <= 9; i++){
    board[x][y] = i;
    if(check(x, y)) func(k+1);
    if(flag) return;
  }
  board[x][y] = 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cin >> board[i][j];
      if(board[i][j] == 0){
        cnt++;
        v.push_back({i, j});
      }
    }
  }
  func(0);
}
