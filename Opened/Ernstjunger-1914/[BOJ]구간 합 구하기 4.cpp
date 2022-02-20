#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, m, tmp=0;
  cin>>n>>m;
  vector<int> v(n+1), vr(n+1);

  for(int i=0; i<n; i++) {
    cin>>v[i];
    tmp+=v[i];
    vr[i+1]=tmp;
  }

  for(int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    cout<<vr[b]-vr[a-1]<<"\n";
  }
  return 0;
}
