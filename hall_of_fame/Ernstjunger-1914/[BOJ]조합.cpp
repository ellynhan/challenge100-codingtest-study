#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

string sarr[105][105];

string add(string a, string b) {
  string num="";
  int res=0, sz=max(a.size(), b.size());

  for(int i=0; i<sz||res; i++) {
    if(i<a.size()) {
      res+=a[i]-'0';
    }

    if(i<b.size()) {
      res+=b[i]-'0';
    }

    num+=res%10+'0';
    res/=10;
  }
  return num;
}

string combination(int n, int m) {
  if(n==m||m==0) {
    return "1";
  }

  string& res=sarr[n][m];

  if(res!="") {
    return res;
  }

  res=add(combination(n-1, m-1), combination(n-1, m));

  return res;
}

int main() {
  ioboost;

  int n, m;
  cin>>n>>m;

  combination(n, m);

  for(int i=sarr[n][m].size()-1; i>=0; i--) {
    cout<<sarr[n][m][i];
  }
  cout<<"\n";
  
  return 0;
}