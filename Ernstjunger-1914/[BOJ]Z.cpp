#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, r, c, result=0;

void func(int x, int y, int sz) {
  if(x==r&&y==c) {
    cout<<result<<"\n";

    return;
  }

  if(r<x+sz&&r>=x&&c<y+sz&&c>=y) {
    func(x, y, sz/2);
    func(x, y+sz/2, sz/2);
    func(x+sz/2, y, sz/2);
    func(x+sz/2, y+sz/2, sz/2);
  } else {
    result+=sz*sz;
  }
}

int main() {
  ioboost;

  cin>>n>>r>>c;
  func(0, 0, pow(2, n));

  return 0;
}