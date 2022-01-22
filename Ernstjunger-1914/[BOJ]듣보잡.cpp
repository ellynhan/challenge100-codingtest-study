#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  int n, m;
  map<string, int> list;
  vector <string> dup;
  cin>>n>>m;

  for(int i=0; i<n+m; i++) {
    string str;
    cin>>str;
    list[str]++;

    if(list[str]>1) {
      dup.push_back(str);
    }
  }

  sort(dup.begin(), dup.end());
  cout<<dup.size()<<"\n";

  for(int i=0; i<dup.size(); i++) {
    cout<<dup[i]<<"\n";
  }
  return 0;
}