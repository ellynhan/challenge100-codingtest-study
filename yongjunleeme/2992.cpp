#include <bits/stdc++.h>
using namespace std;

string s;
char num[7];
char arr[7];
int used[7];
int idx = 0;
int x, y;
int ans = 999999;

void func(int k){
  if(k == idx){
    string str;
    for(int i = 0; i < idx; i++)
      str += arr[i];
    int y = stoi(str);
    if(y > x) ans = min(ans, y);
  }

  for(int i = 0; i < idx; i++){
    if(used[i]) continue;
    used[i] = 1;
    arr[k] = num[i];
    func(k+1);
    used[i] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for(int i = 0; i < s.size(); i++)
    num[idx++] = s[i];

  x = stoi(s);
  func(0);
  if(ans == 999999) cout << 0;
  else cout << ans;
}
