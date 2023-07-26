#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll = long long;

int main() {
  ioboost;

  int n, m, cnt=0;
  set<string> ss;
  cin>>n>>m;

  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    ss.insert(s);
  }

  for(int i=0; i<m; i++) {
    string s;
    cin>>s;

    if(ss.find(s)!=ss.end()) cnt++;
  }
  cout<<cnt<<"\n";
  
  return 0;
}