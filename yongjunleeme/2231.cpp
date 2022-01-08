#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
int n;
int num[MAX];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for(int i = 1; i <= n; i++){
    int tmp = i;
    int sum = i;
    while(tmp){
      sum += tmp % 10;
      tmp /= 10;
    }

    if(sum == n){
      cout << i;
      return 0;
    }
  }
  cout << 0;
}
