#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

ll cost[100001];
ll dist[100001];

int main() {
  ioboost;

  ll res=0, now, n;
  cin>>n;

  for(int i=1; i<n; i++) {
    cin>>dist[i];
  }

  for(int i=0; i<n; i++) {
    cin>>cost[i];
  }

  now=cost[0];
  res=now*dist[1];

  for(int i=1; i<n; i++) {
    if(now<cost[i]) {
      res+=now*dist[i+1];
    } else {
      now=cost[i];
      res+=now*dist[i+1];
    }
  }
  cout<<res<<"\n";
  
  return 0;
}