#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  fastio;

  int m, bit=0;
  cin>>m;

  for(int i=0; i<m; i++) {
    string str;
    int n;
    cin>>str;

    if(str=="add") {
      cin>>n;
      bit|=(1<<n);
    } else if(str=="remove") {
      cin>>n;
      bit&=~(1<<n);
    } else if(str=="check") {
      cin>>n;
      
      if(bit&(1<<n)) {
        cout<<"1\n";
      } else {
        cout<<"0\n";
      }
    } else if(str=="toggle") {
      cin>>n;
      bit^=(1<<n);
    } else if(str=="all") {
      bit=(1<<21)-1;
    } else {
      bit=0;
    }
  }
  return 0;
}
