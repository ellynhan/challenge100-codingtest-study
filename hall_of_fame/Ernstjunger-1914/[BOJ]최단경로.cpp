#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 987654321

using namespace std;

int main() {
  ioboost;

  vector<pair<int, int>> node[20005];
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  int val[20005];
  int n, e, k, u, v, w;
  cin>>n>>e>>k;

  for(int i=0; i<e; i++) {
    cin>>u>>v>>w;
    node[u].push_back(make_pair(v, w));
  }

  for(int i=1; i<=n; i++) {
    val[i]=INF;
  }

  val[k]=0;
  pq.push(make_pair(0, k));

  while(!pq.empty()) {
    int x=pq.top().first, uu=pq.top().second;
    pq.pop();

    for(int i=0; i<node[uu].size(); i++) {
      int vv=node[uu][i].first, ww=node[uu][i].second;

      if(x+ww<val[vv]) {
        val[vv]=x+ww;
        pq.push(make_pair(x+ww, vv));
      }
    }
  }

  for(int i=1; i<=n; i++) {
    if(val[i]==INF) {
      cout<<"INF\n";
    } else {
      cout<<val[i]<<"\n";
    }
  }
  return 0;
}