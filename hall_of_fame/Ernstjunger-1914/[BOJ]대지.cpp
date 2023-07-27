#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int x[100001], y[100001];

int main() {
  ioboost;

  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>x[i]>>y[i];
  }

  sort(x, x+n);
  sort(y, y+n);
  cout<<(x[n-1]-x[0])*(y[n-1]-y[0])<<"\n";

  return 0;
}