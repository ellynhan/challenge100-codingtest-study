#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n, m;
int arr[8];
int res[8];
bool flag[8]={};

void func(int cnt) {
  if(cnt==m) {
    for(int i=0; i<m; i++) {
      cout<<res[i]<<" ";
    }
    cout<<"\n";

    return;
  }

  int tmp=0;

  for(int i=0; i<n; i++) {
    if(!flag[i]&&arr[i]!=tmp) {
      res[cnt]=arr[i];
      tmp=res[cnt];
      flag[i]=1;
      func(cnt+1);
      flag[i]=0;
    }
  }
}

int main() {
  ioboost;

  cin>>n>>m;

  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  sort(arr, arr+n);
  func(0);

  return 0;
}
