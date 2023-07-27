#include <iostream>

using namespace std;

int num[201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while(n--) {
    int i;
    cin >> i;

    num[i + 100] += 1;
  }

  int v;
  cin >> v;
  cout << num[v + 100] << '\n';

  return 0;
}
