#include <iostream>

using namespace std;

long long fibo[91];

int main() {

  int n = 0;
  cin >> n;

  fibo[0] = 0;
  fibo[1] = 1;

  for(int i = 2; i < n + 1; i++) {
    fibo[i] = fibo[i-2] + fibo[i-1];
  }


  cout << fibo[n] << endl;
  
  return 0;
}
