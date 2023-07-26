#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  fastio;

  int t, n;
  int plus[10]={ 0, 1, 2, 4 };
  cin>>t;

  for(int i=4; i<11; i++) {
    plus[i]=plus[i-1]+plus[i-2]+plus[i-3];
  }

  for(int i=0; i<t; i++) {
    cin>>n;
    cout<<plus[n]<<"\n";
  }
  return 0;
}
