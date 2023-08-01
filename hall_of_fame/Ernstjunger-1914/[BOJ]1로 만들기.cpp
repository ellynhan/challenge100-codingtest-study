#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  fastio;

  int i, n;
  int one[1000001]={ 0 };
  cin>>n;

  for(int i=2; i<=n; i++) {
    one[i]=one[i-1]+1;

    if(i%2==0) {
      one[i]=min(one[i], one[i/2]+1);
    }

    if(i%3==0) {
      one[i]=min(one[i], one[i/3]+1);
    }
  }
  cout<<one[n]<<"\n";

  return 0;
}