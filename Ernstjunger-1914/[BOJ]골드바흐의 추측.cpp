#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

const int num=10000;

int main() {
  ioboost;

  bool flag[10001]={};
  int t, n;
  cin>>t;

  for(int i=2; i<=sqrt(num); i++) {
    for(int j=i*i; j<=num; j+=i) {
      if(flag[j]%i==0) {
        flag[j]=1;
      }
    }
  }

  for(int i=0; i<t; i++) {
    cin>>n;

    for(int j=n/2; j>0; j--) {
      if(flag[j]!=1&&flag[n-j]!=1) {
        cout<<j<<" "<<n-j<<"\n";
        break;
      }
    }
  }
  return 0;
}