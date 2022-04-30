#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[100];

int func(int a, int b) {
  return a%b?func(b, a%b):b;
}

int main() {
  ioboost;

  int n;
  cin>>n>>arr[0];

  for(int i=1; i<n; i++) {
    int tmp;
    cin>>arr[i];
    
    tmp=func(arr[0], arr[i]);
    cout<<arr[0]/tmp<<"/"<<arr[i]/tmp<<"\n";
  }
  return 0;
}