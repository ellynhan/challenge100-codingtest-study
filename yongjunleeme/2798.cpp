#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[300005];
int arr[300005];
int isused[300005];
int ans = 0;
vector<int> a;

void func(int k){
  if(k == 3){
    int sum = 0;
    for(int i = 0; i < 3; i++) sum += arr[i];
    if(sum <= m){
      ans = max(ans, sum);
    }
    return;
  }

  for(int i = 0; i < n; i++){
    if(!isused[i]){
      arr[k] = num[i];
      isused[i] = 1;
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  func(0);
  cout << ans;
}
