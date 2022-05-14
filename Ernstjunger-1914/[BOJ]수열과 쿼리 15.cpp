#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[100004];

int main() {
  ioboost;

  int n, m;
  set<pair<int, int>> spi;
  cin>>n;

  for(int i=1; i<n+1; i++) {
    cin>>arr[i];
    spi.insert({ arr[i], i });
  }

  cin>>m;

  while(m--) {
    int query;
    cin>>query;

    if(query!=1) {
      auto a=*spi.begin();
      cout<<a.second<<"\n";
    } else {
      int a, b;
      cin>>a>>b;

      spi.erase({ arr[a], a });
      arr[a]=b;
      spi.insert({ arr[a], a });
    }
  }
  return 0;
}