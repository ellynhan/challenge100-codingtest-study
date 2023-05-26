#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N;
vector<set<int>> arr;
vector<int> dfs_path;
vector<int> bfs_path;
bool visited_dfs[1001] = {false};
bool visited_bfs[1001] = {false};

void dfs(int n){
  visited_dfs[n] = true;
  dfs_path.push_back(n);

  for(auto it=arr[n].begin(); it!=arr[n].end(); it++){
    if(visited_dfs[*it]) continue;
    dfs(*it);
  }
}

void bfs(int n){
  queue<int> q; q.push(n);
  visited_bfs[n] = true;

  while(!q.empty()){
    n = q.front(); q.pop();
    bfs_path.push_back(n);

    for(auto it=arr[n].begin(); it!=arr[n].end(); it++){
      if(visited_bfs[*it]) continue;
      q.push(*it);
      visited_bfs[*it] = true;
    }
  }
}

int main(){
  int M, S; cin >> N >> M >> S;
  
  set<int> tmp_set;
  for(int i=0; i<=N; i++) arr.push_back(tmp_set);

  int a, b;
  while(M--){
    cin >> a >> b;
    arr[a].insert(b);
    arr[b].insert(a);
  }

  dfs(S);
  bfs(S);

  for(int path : dfs_path) cout << path << " ";
  cout << "\n";
  for(int path : bfs_path) cout << path << " ";
}
