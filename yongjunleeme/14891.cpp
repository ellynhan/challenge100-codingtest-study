#include <bits/stdc++.h>
using namespace std;

int k;
deque <bool> gear[4];

void rotate(int n, int dir, int dir2){
  if(dir2 == 0 || dir2 == 1)
    if(n > 0)
      if(gear[n][6] != gear[n-1][2]) rotate(n-1, -1*dir, 0);

  if(dir2 == 1 || dir2 == 2)
    if(n < 3)
      if(gear[n][2] != gear[n+1][6]) rotate(n+1, -1*dir, 2);

  if(dir == -1){
    bool tmp = gear[n].front();
    gear[n].pop_front();
    gear[n].push_back(tmp);
  }

  if(dir == 1){
    bool tmp = gear[n].back();
    gear[n].pop_back();
    gear[n].push_front(tmp);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 8; j++){
      char a;
      cin >> a;
      gear[i].push_back(a - 48);
    }
  }

  cin >> k;
  for(int i = 0; i < k; i++){
    int n, dir;
    cin >> n >> dir;
    rotate(n-1, dir, 1);
  }

  int ans = 0;
  for(int i = 0; i < 4; i++)
    if(gear[i].front()) ans += pow(2, i);
  cout << ans;
}
