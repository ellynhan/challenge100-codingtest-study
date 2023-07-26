#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[1001], ans[1001];

int func(int a, int b) {
  return a%b?func(b, a%b):b;
}

int main() {
  ioboost;

  int n, tmp, cnt(0);
  cin>>n;

  for(int i=0; i<n; i++) cin>>arr[i];
  sort(arr, arr+n);

  tmp=arr[1]-arr[0];

  for(int i=2; i<n; i++) tmp=func(tmp, arr[i]-arr[i-1]);

  for(int i=1; i*i<=tmp; i++) {
    if(tmp%i==0) {
      ans[cnt++]=i;
      
      if(i!=tmp/i) {
        ans[cnt++]=tmp/i;
      }
    }
  }

  sort(ans, ans+cnt);

  for(int i=0; i<cnt; i++) {
    if(ans[i]!=1) {
      cout<<ans[i]<<" ";
    }
  }
  cout<<"\n";
  
  return 0;
}