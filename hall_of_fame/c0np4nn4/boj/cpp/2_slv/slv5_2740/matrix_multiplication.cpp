#include <iostream>

using namespace std;

int A[101][101];
int B[101][101];
int C[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, c;
  cin >> r >> c;

  for (int i = 1; i <= r; i++)  {
    for (int j = 1; j <= c; j++) {
      cin >> A[i][j];
      // cout << i << ", " << j << "): " << A[i][j] << endl;
    }
  }

  int _c, k;
  cin >> _c >> k;

  for (int i = 1; i <= c; i++)  {
    for (int j = 1; j <= k; j++) {
      cin >> B[i][j];
      // cout << i << ", " << j << "): " << B[i][j] << endl;
    }
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= k; j++) {
      int sum = 0;
      for (int t = 1; t <= c; t++) {
        // cout << "[+] " << A[i][t] << ", " << B[t][j] << endl;
        sum += A[i][t] * B[t][j];
      }

      C[i][j] = sum;
    }
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= k; j++) {
      cout << C[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
