#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, x;
  string str;
  queue<int> qi;
  cin>>n;

  while(n--) {
    cin>>str;

    if(str=="push") {
      cin>>x;
      qi.push(x);
    } else if(str=="pop") {
      if(!qi.empty()) {
        cout<<qi.front()<<"\n";
        qi.pop();
      } else {
        cout<<-1<<"\n";
      }
    } else if(str=="size") {
      cout<<qi.size()<<"\n";
    } else if(str=="empty") {
      cout<<qi.empty()<<"\n";
    } else if(str=="front") {
      if(!qi.empty()) {
        cout<<qi.front()<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    } else if(str=="back") {
      if(!qi.empty()) {
        cout<<qi.back()<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    }
  }
  return 0;
}