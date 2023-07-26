#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

using namespace std;

int main() {
  ioboost;

  int n;
  ll result=0, isoverflow=0;

  for(int i=0; i<3; i++) {
    cin>>n;
    result=isoverflow=0;

    for(int j=0; j<n; j++) {
      ll tmp;
      cin>>tmp;

      if(result>0&&tmp>0&&tmp>LLONG_MAX-result) {
        isoverflow+=1;
      } else if(result<0&&tmp<0&&tmp<LONG_MIN-result) {
        isoverflow-=1;
      }
      result+=tmp;
    }

    if(isoverflow<0) {
      cout<<"-\n";
    } else if(isoverflow>0) {
      cout<<"+\n";
    } else if(result==0) {
      cout<<0<<"\n";
    } else if(result<0) {
      cout<<"-\n";
    } else if(result>0) {
      cout<<"+\n";
    }
  }
  return 0;
}