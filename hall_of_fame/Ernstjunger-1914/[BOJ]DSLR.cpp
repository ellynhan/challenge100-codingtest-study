#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int a, b;
bool vis[10000];

void func() {
  queue<pair<int, string>> qp;
  qp.push(make_pair(a, ""));
  vis[a]=1;

  while(!qp.empty()) {
    int curint=qp.front().first;
    string curstr=qp.front().second;
    qp.pop();

    if(curint==b) {
      cout<<curstr<<"\n";

      return;
    }

    int d, s, l, r;

    d=(curint*2)%10000;
    if(!vis[d]) {
      vis[d]=1;
      qp.push(make_pair(d, curstr+"D"));
    }

    s=curint-1<0?9999:curint-1; 
    if(!vis[s]) {
      vis[s]=1;
      qp.push(make_pair(s, curstr+"S"));
    }
    
    l=(curint%1000)*10+(curint/1000);
    if(!vis[l]) {
      vis[l]=1;
      qp.push(make_pair(l, curstr+"L"));
    } 
    
    r=curint/10+(curint%10)*1000;
    if(!vis[r]) {
      vis[r]=1;
      qp.push(make_pair(r, curstr+"R"));
    }
  }
}

int main() {
  fastio;

  int t;
  cin>>t;

  for(int i=0; i<t; i++) {
    cin>>a>>b;
    memset(vis, false, sizeof(vis));
    func();
  }
  return 0;
}