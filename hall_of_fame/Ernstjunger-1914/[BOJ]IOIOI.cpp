#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, m, result=0;
  string str;
  cin>>n>>m>>str;

  for(int i=1; i<str.size(); i++) {
    int cnt=0;

    if(str[i-1]=='I') {
      while(str[i]=='O'&&str[i+1]=='I') {
        i+=2;
        cnt++;

        if(cnt==n) {
          cnt--; result++;
        }
      }
    }
  }
  cout<<result<<"\n";

  return 0;
}