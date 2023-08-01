#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int t;
  priority_queue<int, vector<int>, greater<int>> min;
  priority_queue<int> max;
  cin>>t;

  while(t--) {
    int a, sz;
    cin>>a;

    if(max.size()==min.size()) {
      max.push(a);
    } else {
      min.push(a);
    }

    if(!max.empty()&&!min.empty()&&max.top()>min.top()) {
      int minv, maxv;
      minv=min.top();
      maxv=max.top();

      min.pop();
      max.pop();

      min.push(maxv);
      max.push(minv);
    }
    cout<<max.top()<<"\n";
  }
  return 0;
}