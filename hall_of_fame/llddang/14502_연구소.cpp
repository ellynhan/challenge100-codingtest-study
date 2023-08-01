#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
int arr[8][8];
int spread[8][8];
bool visited[8][8];
struct pos{int i, j;};
vector<pos> virus;

void init(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 2) virus.push_back({i, j});
    }
  }
}

void spreadVirus(int ci, int cj){
  spread[ci][cj] = 2;

  int di[] = {0, 0, 1, -1};
  int dj[] = {1, -1, 0, 0};

  int ni, nj;
  for(int i=0; i<4; i++){
    ni = ci + di[i]; nj = cj + dj[i];
    if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;
    if(visited[ni][nj]) continue;

    if(arr[ni][nj] == 0 && spread[ni][nj] != 2) spreadVirus(ni, nj);
  }
}

void lab(int n){
  if(n == 0){
    memset(spread, 0, sizeof(spread));
    for(pos p:virus) spreadVirus(p.i, p.j);
    
    int safeArea = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(arr[i][j] == 0 && spread[i][j] == 0) safeArea++;
      }
    }
    answer = max(answer, safeArea);
    return;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(arr[i][j] != 0) continue;

      arr[i][j] = 1;
      lab(n-1);
      arr[i][j] = 0;
    }
  }
}

int main(){
  init();
  lab(3);
  cout << answer;
}
