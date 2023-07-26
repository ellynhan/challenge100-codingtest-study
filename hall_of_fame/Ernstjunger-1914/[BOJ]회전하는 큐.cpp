#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, m, cnt=0;
  deque<int> di;
  cin>>n>>m;

  for(int i=1; i<=n; i++) {
    di.push_back(i);
  }

  for(int i=0; i<m; i++) {
    int num, index;
    cin>>num;

    for(int i=0; i<di.size(); i++) {
      if(di[i]==num) {
        index=i;
        break;
      }
    }

    if(index<di.size()-index) {
      while(1) {
        if(di.front()==num) {
          di.pop_front();
          break;
        }
        cnt++;
        di.push_back(di.front());
        di.pop_front();
      }
    } else {
      while(1) {
        if(di.front()==num) {
          di.pop_front();
          break;
        }
        cnt++;
        di.push_front(di.back());
        di.pop_back();
      }
    }
  }
  cout<<cnt<<"\n";
  
  return 0;
}