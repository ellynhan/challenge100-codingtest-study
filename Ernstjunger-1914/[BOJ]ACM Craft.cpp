#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t;
  cin>>t;

  while(t--) {
    int n, k;
    int time[1002];
    cin>>n>>k;

    for(int i=1; i<=n; i++) {
      cin>>time[i];
    }

    vector<int> vi[1002];
    int res[1002], ind[1002]={};
    queue<int> qi;

    while(k--) {
      int a, b;
      cin>>a>>b;
      vi[a].push_back(b);
      ind[b]++;
    }

    int w;
    cin>>w;

    for(int i=1; i<=n;  i++) {
      if(ind[i]==0) qi.push(i);
      res[i]=time[i];
    }

    while(!qi.empty()) {
      int tmp=qi.front();
      qi.pop();

      for(int i=0; i<vi[tmp].size(); i++) {
        int nxt=vi[tmp][i];
        ind[nxt]--;
        res[nxt]=max(res[nxt], res[tmp]+time[nxt]);

        if(ind[nxt]==0) qi.push(nxt);
      }
    }
    cout<<res[w]<<"\n";
  }
  return 0;
}