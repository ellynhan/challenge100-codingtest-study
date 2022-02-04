#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 1000000000

using namespace std;

int n, m, r, a, b, l, result=0;
int item[102]={ 0 };
int dist[102]={ 0 };
vector<pair<int, int>> vp[102];

void func(int x) {
  queue<int> q;
  int cnt=0;

  for(int i=1; i<=n; i++) {
    dist[i]=INF;
  }

  dist[x]=0;
  q.push(x);

  while(!q.empty()) {
    int node=q.front();
    int dis=dist[node];
    q.pop();

    for(int i=0; i<vp[node].size(); i++) {
      int next_node=vp[node][i].first, next_dis=vp[node][i].second;

      if(dis+next_dis<dist[next_node]) {
        dist[next_node]=dis+next_dis;
        q.push(next_node);
      }
    } 
  }

  for(int i=1; i<=n; i++) {
    if(dist[i]<=m) {
      cnt+=item[i];
    }
  }
  
  result=max(result, cnt);
}

int main() {
  ioboost;

  cin>>n>>m>>r;

  for(int i=1; i<=n; i++) {
    cin>>item[i];
  }

  for(int i=0; i<r; i++) {
    cin>>a>>b>>l;
    vp[a].push_back({ b, l });
    vp[b].push_back({ a, l });
  }

  for(int i=1; i<=n; i++) {
    func(i);
  }
  cout<<result<<"\n";

  return 0;
}