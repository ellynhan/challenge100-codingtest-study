#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int res[1000001];
int seq[1000001];
stack<int> si;

int main() {
  ioboost;

  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>seq[i];
  }

  for(int i=n-1; i>=0; i--) {
    while(!si.empty()&&si.top()<=seq[i]) {
      si.pop();
    }

    if(si.empty()) {
      res[i]=-1;
    } else {
      res[i]=si.top();
    }
    si.push(seq[i]);
  }

  for(int i=0; i<n; i++) {
    cout<<res[i]<<" ";
  }
  cout<<"\n";
  
  return 0;
}