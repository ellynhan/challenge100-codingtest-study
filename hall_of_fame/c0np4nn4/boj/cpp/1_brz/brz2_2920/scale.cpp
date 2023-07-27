#include <iostream>

using namespace std;

int scale[8];
int mode = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> scale[0]; // base
  cin >> scale[1]; // mode

  if (scale[0] > scale[1]) mode = 1;
  if (scale[0] < scale[1]) mode = 2;

  for (int i = 2; i < 8; i++) {
    cin >> scale[i];

    if (mode == 1) {
      if (scale[i - 1] < scale[i]) {
        mode = 3;

        break;
      }
    }

    if (mode == 2) {
      if (scale[i - 1] > scale[i]) {
        mode = 3;

        break;
      }
    }

  }

  if (mode == 1) {
    cout << "descending" << '\n';
  }
  if (mode == 2) {
    cout << "ascending" << '\n';
  }
  if (mode == 3) {
    cout << "mixed" << '\n';
  }

  return 0;
}
