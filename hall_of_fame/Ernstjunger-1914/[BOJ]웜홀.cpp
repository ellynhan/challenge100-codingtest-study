#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 30'000'000

using namespace std;
using ll=long long;

int n, m, w;
struct info {
  int s, e, t;
};

bool func(int n, vector<info> vi) {
  vector<int> dist(n+1, INF);
  int s, e, t;
  dist[1]=0;

  for(int i=1; i<n; i++) {
    for(int j=0; j<vi.size(); j++) {
      s=vi[j].s;
      e=vi[j].e;
      t=vi[j].t;

      if(dist[s]+t<dist[e]) {
        dist[e]=dist[s]+t;
      }
    }
  }

  for(int i=0; i<vi.size(); i++) {
    s=vi[i].s;
    e=vi[i].e;
    t=vi[i].t;

    if(dist[s]+t<dist[e]) {
      return true;
    }
  }
  return false;
}

int main() {
  ioboost;

  int tc, s, e, t;
  cin>>tc;

  while(tc--) {
    vector<info> vi;
    cin>>n>>m>>w;

    for(int i=0; i<m; i++) {
      cin>>s>>e>>t;
      vi.push_back({ s, e, t });
      vi.push_back({ e, s, t });
    }

    for(int i=0; i<w; i++) {
      cin>>s>>e>>t;
      vi.push_back({ s, e, -t });
    }

    if(!func(n, vi)) {
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
    }
  }
  return 0;
}
