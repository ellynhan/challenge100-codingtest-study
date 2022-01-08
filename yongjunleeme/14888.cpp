#include <bits/stdc++.h>
using namespace std;

int n;
int num[102];
int cal[4];
int mx = -2147483647;
int mn = 2147483647;

void func(int ans, int k){
  if(k == n){
    mx = max(mx, ans);
    mn = min(mn, ans);
    return;
  }

  for(int i = 0; i < 4; i++){
    if(cal[i] == 0) continue;
    cal[i]--;
      if(i == 0) func(ans + num[k], k+1);
      else if(i == 1) func(ans - num[k], k+1);
      else if(i == 2) func(ans * num[k], k+1);
      else if(i == 3) func(ans / num[k], k+1);
    cal[i]++;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  for(int i = 0; i < 4; i++) cin >> cal[i];
  func(num[0], 1);
  cout << mx << "\n" << mn << "\n";
}
