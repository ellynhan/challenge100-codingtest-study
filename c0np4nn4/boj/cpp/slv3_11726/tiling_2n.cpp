#include <iostream>

using namespace std;

long long tile[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  tile[0] = 0;
  tile[1] = 1;
  tile[2] = 2;
  tile[3] = 3;

  for (int i = 4; i <= n; i++) {
    long long tmp = tile[i-2] + tile[i-1];
    tile[i] = tmp % 10007;
  }

  cout << tile[n]<< endl;

  return 0;
}
