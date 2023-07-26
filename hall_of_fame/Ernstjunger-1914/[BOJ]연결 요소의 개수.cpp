#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> adj[1001];
bool flag[1001];

void func(int x) {
  flag[x]=1;

  for(int i=0; i<adj[x].size(); i++) {
    int y=adj[x][i];

    if(!flag[y]) {
      func(y);
    }
  }
}

int main() {
  ioboost;

  int n, m, cnt=0;
  cin>>n>>m;

  for(int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=1; i<=n; i++) {
    if(!flag[i]) {
      cnt++;
      func(i);
    }
  }
  cout<<cnt<<"\n";

  return 0;
}