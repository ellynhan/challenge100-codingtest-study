#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n;
  cin>>n;

  if(n%2==0) {
    cout<<"CY\n";
  } else {
    cout<<"SK\n";
  }
  return 0;
}