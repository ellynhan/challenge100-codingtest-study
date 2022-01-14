#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  priority_queue<int, vector<int>, greater<int>> pvg;
  int n;
  cin>>n;

  while(n--) {
    int tmp;
    cin>>tmp;
    
    switch(tmp) {
      case 0:
        if(pvg.size()) {
          cout<<pvg.top()<<"\n";
          pvg.pop();
        } else {
          cout<<0<<"\n";
        }

        break;
      default:
      pvg.push(tmp);

      break;
    }
  }
  return 0;
}