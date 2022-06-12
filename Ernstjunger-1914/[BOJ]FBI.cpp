#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  string fbiopenup="FBI";
  vector<string> vstr(5);
  vector<int> vi;

  for(auto &a: vstr) {
    cin>>a;
  }

  for(int i=0; i<5; i++) {
    if(vstr[i].find(fbiopenup, 0)!=-1) {
      vi.push_back(i+1);
    }
  }

  if(vi.size()!=0) {
    for(auto a: vi) {
      cout<<a<<" ";
    }
  } else {
    cout<<"HE GOT AWAY!\n";
  }
  return 0;
}