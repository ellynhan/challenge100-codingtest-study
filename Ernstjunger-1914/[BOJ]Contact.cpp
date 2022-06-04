#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;


int main() {
  ioboost;

  int t;
  cin>>t;

  while(t--) {
    string str;
    cin>>str;

    cout<<(regex_match(str, regex("(100+1+|01)+"))?"YES":"NO")<<"\n";
  }
  return 0;
}