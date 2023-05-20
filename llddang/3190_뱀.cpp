#include <iostream>
#include <queue>
using namespace std;

int map[100][100]={0,};
queue<pair<int, int>> point;
struct cha{int t; char d;};
cha change[100];

int main(){
  int N; cin >> N;
  int K; cin >> K;
  int x, y;
  for(int i=0; i<K; i++){
    cin >> y >> x;
    map[y-1][x-1] = 1;
  }
  int L; cin >> L;
  for(int i=0; i<L; i++){
    cin >> change[i].t >> change[i].d;
  }

  int dir = 0;
  int ci = 0, cj = 0;
  int di[] = {0, 1, 0, -1};
  int dj[] = {1, 0, -1, 0};
  int time=0;
  point.push({ci, cj});
  map[ci][cj] = 2;

  for(int i=0; i<=L; i++){
    while(change[i].t != time || i == L){
      time++;
      ci += di[dir]; cj += dj[dir];
      if(0 > ci || ci >= N || 0 > cj || cj >= N || map[ci][cj] == 2){
        cout << time;
        return 0;
      }
      if(map[ci][cj] == 1){
        map[ci][cj] = 2;
        point.push({ci, cj});
      } else {
        map[ci][cj] = 2;
        point.push({ci, cj});
        map[point.front().first][point.front().second] = 0;
        point.pop();
      }
    }
    if(change[i].d == 'L') dir = (dir + 3) % 4;
    if(change[i].d == 'D') dir = (dir + 1) % 4;
  }
  return 0;
}
