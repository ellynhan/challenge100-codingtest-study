#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int left = 0, right = 0, tmp;
  while (N--){
    cin >> tmp;
    if (left > right)
      right += tmp;
    else
      left += tmp;
  }
  int gap = max(left, right) - min(left, right);
  int weight[] = {100, 50, 20 ,10, 5, 2, 1};
  int cnt = 0;
  for(int i=0; i < sizeof(weight) / sizeof(int); i++){
    cnt += gap / weight[i];
    gap %= weight[i];
  }
  cout << cnt;
}
