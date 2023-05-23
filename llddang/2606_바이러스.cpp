#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[101];
int visited[101] = {false};

vector<vector<int>> vec(101, vector<int>(0));

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M; cin >> N >> M;

  int a, b;
  for(int i=0; i<M; i++){
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  queue<int> que; que.push(1);
  visited[1] = true;
  int idx, cnt = 0;
  while(!que.empty()){
    idx = que.front(); que.pop();

    for(int i=0; i<vec[idx].size(); i++){
      if(visited[vec[idx][i]]) continue;

      visited[vec[idx][i]] = true;
      que.push(vec[idx][i]);
      cnt++;
    }
  }

  cout << cnt;
}
