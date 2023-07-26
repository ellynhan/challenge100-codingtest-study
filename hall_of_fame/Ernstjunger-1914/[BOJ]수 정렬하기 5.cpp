#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  vector<int> desc;
  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    int tmp;
    cin>>tmp;
    desc.push_back(tmp);
  }

  sort(desc.begin(), desc.end());

  for(int i=0; i<n; i++) {
    cout<<desc[i]<<"\n";
  }

  return 0;
}