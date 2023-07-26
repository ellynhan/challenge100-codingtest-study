#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  fastio;

  int n, time=0, result=0;
  cin>>n;
  int line[n];

  for(int i=0; i<n; i++) {
    cin>>line[i];
  }

  sort(line, line+n);

  for(int i=0; i<n; i++) {
    time+=line[i];
    result+=time;
  }
  cout<<result<<"\n";

  return 0;
}