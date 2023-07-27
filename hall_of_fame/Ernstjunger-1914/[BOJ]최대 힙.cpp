#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  int n;
  priority_queue<int> pq;
  cin>>n;

  for(int i=0; i<n; i++) {
    int tmp;
    cin>>tmp;

    if(tmp!=0) {
      pq.push(tmp);
    } else {
      if(pq.empty()) {
        cout<<0<<"\n";
      } else {
        cout<<pq.top()<<"\n";
        pq.pop();
      }
    }
  }
  return 0;
}