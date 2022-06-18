#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[50];
pair<int, int> pi[50];

void func(int n) {
  for(int i=0; i<n; i++) arr[pi[i].second]=i;
  for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int main() {
  ioboost;

  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>pi[i].first;
    pi[i].second=i;
  }

  sort(pi, pi+n);
  func(n);
  cout<<"\n";
  
  return 0;
}