#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int queen[15];
int n, res=0;

bool check(int l) {
  for(int i=0; i<l; i++) {
    if(queen[i]==queen[l]||abs(queen[l]-queen[i])==l-i) {
      return false;
    }
  }
  return true;
}

void func(int l) {
  if(l==n) {
    res++;
  } else {
    for(int i=0; i<n; i++) {
      queen[l]=i;

      if(check(l)) {
        func(l+1);
      }
    }
  }
}

int main() {
  ioboost;

  cin>>n;
  func(0);
  cout<<res<<"\n";
  
  return 0;
}