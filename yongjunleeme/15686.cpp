#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 1) home.push_back({i, j});
      if(board[i][j] == 2) chicken.push_back({i, j});
    }
  }
  vector<int> brute(chicken.size(), 1); // 1로 초기화된 chicken.size()개의 원소를 가지는 vector
  fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
  int mn = 0x7f7f7f7f;
  do{
    int dis = 0;
    for(auto h : home){
      int tmp = 0x7f7f7f7f;
      for(int i = 0; i < chicken.size(); i++){
        if(brute[i] == 0) continue;
        tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
      }
      dis += tmp;
    }
    mn = min(mn, dis);
  }while(next_permutation(brute.begin(), brute.end()));
  cout << mn;
}
