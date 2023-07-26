#include <iostream>
#include <vector>
using namespace std;

struct pos{int i, j;};
pos goal;
int N, M;
char map[10][10];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int answer = 11;

void dfs(int n, int dir, pos red, pos blue){
  int ri = red.i, rj = red.j;
  int bi = blue.i, bj = blue.j;
  int rni, rnj, bni, bnj;
  bool move = true;
  bool redIn = false, blueIn = false;
  while(move){
    move = false;
    rni = ri + di[dir]; rnj = rj + dj[dir];
    while((rni != bi || rnj != bj) && map[rni][rnj] != '#'){
      ri = rni; rj = rnj;
      if(map[ri][rj] == 'O'){ redIn = true; ri = -1; rj = -1; break;}
      rni = ri + di[dir]; rnj = rj + dj[dir];
      move = true;
    }

    bni = bi + di[dir]; bnj = bj + dj[dir];
    while((bni != ri || bnj != rj) && map[bni][bnj] != '#'){
      bi = bni; bj = bnj;
      if(map[bi][bj] == 'O'){ blueIn = true; break;}
      bni = bi + di[dir]; bnj = bj + dj[dir];
      move = true;
    }

    if(blueIn) return;
    if(redIn){answer = min(answer, n); return;}
  }
  if(n == 10) return;
  red.i = ri; red.j = rj;
  blue.i = bi; blue.j = bj;

  dfs(n+1, 0, red, blue);
  dfs(n+1, 1, red, blue);
  dfs(n+1, 2, red, blue);
  dfs(n+1, 3, red, blue);
}

int main(){
  cin >> N >> M;
  pos red, blue;
  for(int i=0; i<N; i++)
  for(int j=0; j<M; j++){ 
    cin >> map[i][j];
    if(map[i][j] == 'R'){ red.i = i; red.j = j; map[i][j] = '.';}
    else if(map[i][j] == 'B'){ blue.i = i; blue.j = j; map[i][j] = '.';}
    else if(map[i][j] == 'O'){ goal.i = i; goal.j = j; }
  }

  dfs(1, 0, red, blue);
  dfs(1, 1, red, blue);
  dfs(1, 2, red, blue);
  dfs(1, 3, red, blue);

  if(answer == 11) answer = -1;
  cout << answer;
}
