#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
bool vis[102];
vector <int> v[102];

void func(int k){
  queue <int> q;
  q.push(k);
  vis[k] = 1;
  while(!q.empty()){
    cnt++;
    int cur = q.front(); q.pop();
    for(int i = 0; i < v[cur].size(); i++){
      int nk = v[cur][i];
      if(vis[nk]) continue;
      vis[nk] = 1;
      q.push(nk);
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  func(1);
  cout << cnt-1;
}
