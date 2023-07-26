#include <iostream>
#include <vector>

using namespace std;

vector<int> divisor;

int main() {
  int n;
  cin >> n;

  int k;
  cin >> k;

  divisor.push_back(0);
  divisor.push_back(1);

  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      divisor.push_back(i);
    }
  }

  cout << divisor[k - 1] << endl;

  return 0;
}
