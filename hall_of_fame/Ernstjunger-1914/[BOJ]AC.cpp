#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef size_t st;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

int main() {
  ioboost;

  int t, n;
  cin>>t;

  while(t--) {
    deque<int> d;
    bool err=0, res=0;
    string str, order, s="";
    cin>>order;
    cin>>n;
    cin>>str;

    for(int i=0; i<str.length(); i++) {
      if(isdigit(str[i])) {
        s+=str[i];
      } else {
        if(!s.empty()) {
          d.push_back(stoi(s));
          s="";
        }
      }
    }

    for(auto t: order) {
      if(t=='R') {
        if(!res) {
          res=1;
        } else {
          res=0;
        }
      } else {
        if(d.empty()) {
          cout<<"error"<<"\n";
          err=1;

          break;
        }

        if(!res) {
          d.pop_front();
        } else {
          d.pop_back();
        }
      }
    }

    if(!err) {
      cout<<"[";
    }

    if(res&&!d.empty()) {
      for(auto t=d.rbegin(); t!=d.rend(); t++) {
        if(t!=d.rend()-1) {
          cout<<*t<<",";
        } else {
          cout<<*t;
        }
      }
    } else if(!res&&!d.empty()) {
      for(auto t=d.begin(); t!=d.end(); t++) {
        if(t!=d.end()-1) {
          cout<<*t<<",";
        } else {
          cout<<*t;
        }
      }
    }

    if(!err) {
      cout<<"]\n";
    }
  }
  return 0;
}