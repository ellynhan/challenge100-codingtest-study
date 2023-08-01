#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  vector<int> asc;
  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    int tmp;
    cin>>tmp;
    asc.push_back(tmp);
  }

  sort(asc.begin(), asc.end());
  asc.erase(unique(asc.begin(), asc.end()), asc.end());

  for(int i=0; i<asc.size(); i++) {
    cout<<asc[i]<<" ";
  }
  cout<<"\n";

  return 0;
}