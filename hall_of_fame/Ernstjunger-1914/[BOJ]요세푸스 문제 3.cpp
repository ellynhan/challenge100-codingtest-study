#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int func(int a, int b) {
  int r=1;

  for(int i=2; i<=a; i++) {
    int c=b%i;

    if(r<=i-c) {
      r+=c;
    } else {
      r-=(i-c);
    }
  }
  return r;
}

int main() {
  ioboost;

  int n, k;
  cin>>n>>k;
  cout<<func(n, k)<<"\n";

  return 0;
}