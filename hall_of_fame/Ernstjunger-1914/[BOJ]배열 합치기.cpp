#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  int n, m;
  vector<int> v;
  cin>>n>>m;

  for(int i=0; i<n; i++) {
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
  }

  for(int i=0; i<m; i++) {
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<n+m; i++) {
    cout<<v[i]<<" ";
  }
  cout<<"\n";

  return 0;
}
