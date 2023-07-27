#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  string str, s;
  set<string> ss;
  cin>>str;

  for(int i=0; i<str.size(); i++) {
    s="";

    for(int j=i; j<str.size(); j++) {
      s+=str[j];
      ss.insert(s);
    }
  }
  cout<<ss.size()<<"\n";
  
  return 0;
}