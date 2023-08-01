#include <iostream>
#define for(a, b, c) for(int a=b; a<c; a++)
using namespace std;

int N,M;
int board[50][50];
int answer = 0;

int main(){
  cin >> N >> M;
  int ci, cj, dir; cin >> ci >> cj >> dir;
  int cnt = 0;
  for(i, 0, N)
    for(j, 0, M) cin >> board[i][j];
  if(dir % 2 == 1) dir = 4 - dir;
  
  int di[] = {-1, 0, 1, 0};
  int dj[] = {0, -1, 0, 1};
  bool allClean;
  int ni, nj;

  while(board[ci][cj] != 1){
    if(board[ci][cj] == 0){
      answer++;
      board[ci][cj] = 2;
    }

    allClean = true;
    for(i, 1, 5){
      ni = ci + di[(dir+i) % 4];
      nj = cj + dj[(dir+i) % 4];

      if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;
      if(board[ni][nj] == 0){
        ci = ni; cj = nj; dir = (dir+i) % 4;
        allClean = false;
        break;
      }
    }

    if(allClean){
      ni = ci - di[dir];
      nj = cj - dj[dir];
      if(0 <= ni && ni < N && 0 <= nj && nj < M){
        ci = ni; cj = nj;
      }
    }
  }

  cout << answer;

}
