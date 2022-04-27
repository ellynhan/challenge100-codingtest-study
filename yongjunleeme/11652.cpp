#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 1;
long long mxval = -(1ll << 62) - 1;
long long mxcnt = 0;
long long a[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  a[n] = (1ll << 62) + 1;
  for(int i = 1; i <= n; i++){
    if(a[i-1] == a[i]) cnt++;
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = a[i-1];
      }
      cnt = 1;
    }
  }
  cout << mxval;
}
