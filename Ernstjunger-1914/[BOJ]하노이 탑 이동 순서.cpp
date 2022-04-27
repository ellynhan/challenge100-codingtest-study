#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

void func(int a, int b, int c, int d) {
  if(d==1) {
    cout<<a<<" "<<c<<"\n";
  } else {
    func(a, c, b, d-1);
    cout<<a<<" "<<c<<"\n";
    func(b, a, c, d-1);
  }
}

int main() {
  ioboost;

  int n;
  cin>>n;
  cout<<(int)pow(2, n)-1<<"\n";
  func(1, 2, 3, n);
    
  return 0;
}