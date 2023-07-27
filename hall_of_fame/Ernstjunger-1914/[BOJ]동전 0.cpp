#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, k, result=0;
  int arr[11]={};
  cin>>n>>k;

  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  for(int i=n-1; i>=0; i--) {
    result+=k/arr[i];
    k%=arr[i];
  }
  cout<<result<<"\n";

  return 0;
}