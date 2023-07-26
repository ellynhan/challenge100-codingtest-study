#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int a, b, c, d, n, result=0;
int cnt[8001];
int co[500001];

int main() {
  ioboost;

  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>co[i];

    result+=co[i];
    cnt[co[i]+4000]++;
  }

  int flag, max=0;
  sort(co, co+n);

  for(int i=0; i<=8000; i++) {
    if(cnt[i]>max) {
      max=cnt[i];
      flag=i;
    }
  }

  for(int i=flag+1; i<=8000; i++) {
    if(cnt[i]==max) {
      flag=i;
      break;
    }
  }

  a=round(double(result)/n);
  b=co[(n-1)/2];
  c=flag-4000;
  d=co[n-1]-co[0];
  cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n";

  return 0;
}