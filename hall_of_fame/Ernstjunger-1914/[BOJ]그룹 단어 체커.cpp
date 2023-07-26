#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  fastio;

  int n, cnt=0;
  string str;
  bool flag;
  cin>>n;

  for(int i=0; i<n; i++) {
    flag=1;
    cin>>str;

    for(int j=0; j<str.length(); j++) {
      for(int k=0; k<j; k++) {
        if(str[j]!=str[j-1]&&str[j]==str[k]) {
          flag=0;

          break;
        }
      }
    }
    if(flag) {
      cnt++;
    }
  }
  cout<<cnt<<"\n";

  return 0;
}