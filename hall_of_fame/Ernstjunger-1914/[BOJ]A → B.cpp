#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long l;
typedef long long ll;
typedef size_t st;

int main() {
  ioboost;

  l a, b, ans=1;
  cin>>a>>b;

  while(b>=a) {
    if(a==b) {
      cout<<ans<<"\n";

      return 0;
    }

    ans++;

    if(b%2==0) {
      b/=2;
    } else if(b%10==1) {
      b-=1;
      b/=10;
    } else {
      break;
    }
  }
  cout<<-1<<"\n";
  
  return 0;
}