#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int N, k;
  cin >> N >> k;
  int cnt = 0;
  int n = 1;
  vector<int> store;

  while (N > 0){
    if (N % 2 == 1 && k > 0){
      N = (N - 1) / 2;
      store.push_back(pow(2, (n-1)));
      k--;
    } else if (N % 2 == 1 && k == 0){
      store.push_back(pow(2, (n-1)));
      int i=0, j=1;
      while(store[0] * pow(2, i) != store[1]){
        cnt += store[0] * pow(2, i);
        i++;
      }
      while(j < store.size() - 2 && store[j] * 2 == store[j+1]){
        j++;
      }
      if(j == store.size() - 1){
        k += j;
        store.clear();
        N = (N + 1) / 2;
      } else {
        k += j - 1;
        int tmp = store[j]*2, tmp2;
        for(i=0; i<=j; i++){
          store.erase(store.begin());
        }
        for(i=0; i < store.size(); i++){
          tmp2 = store[i];
          store[i] = tmp;
          tmp = tmp2;
        }
        store.push_back(tmp);
        N = (N - 1) / 2;
      }
    } else {
      N = N / 2;
    }
    n++;
  }
  cout << cnt;
  return 0;
}
