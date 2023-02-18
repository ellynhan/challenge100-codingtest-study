#include <iostream>

using namespace std;

int comb[12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  comb[0] = 0;
  comb[1] = 1;
  comb[2] = 2;
  comb[3] = 4;
  for (int i = 4; i < 12; i++) {
    comb[i] = comb[i-1] + comb[i-2] + comb[i-3];
  }

  int t = 0;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    cout << comb[n] << endl;
  }
  return 0;
}
