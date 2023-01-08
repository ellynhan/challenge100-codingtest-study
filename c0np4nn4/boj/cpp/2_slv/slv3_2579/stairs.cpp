#include <iostream>

using namespace std;

int stairs[300];
int sum[300];

int main() {
  int n = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> stairs[i];
  }

  sum[0] = stairs[0];
  sum[1] = stairs[0] + stairs[1];
  sum[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

  for (int i = 3; i < n; i++) {
    sum[i] = max(sum[i - 2] + stairs[i], sum[i - 3] + stairs[i - 1] + stairs[i]);
  }

  cout << sum[n-1] << endl;

  return 0;
}
