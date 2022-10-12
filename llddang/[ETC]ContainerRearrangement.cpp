#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N;

int main(){
  cin >> N;
  vector<int> cont;

  int n;
  ll sum = 0;
  int i;
  for (i = 0; i < N; i++){
    cin >> n;
    sum += n;
    cont.push_back(n);
  }

  int plus = 0, minus = 0;
  int m = sum / N;
  for (i = 0; i < N; i++){
    if (cont[i] > m){
      plus += cont[i] - m - 1;
    } else {
      minus += m - cont[i];
    }
  }
  
  cout << max(plus, minus);
}
