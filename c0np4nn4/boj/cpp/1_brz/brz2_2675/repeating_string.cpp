#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    int r;
    cin >> r;

    string msg;
    cin >> msg;

    for (int i = 0; i < msg.size(); i++) {
      for (int j = 0; j < r; j++) {
        cout << msg[i];
      }
    }
    cout << '\n';
  }
  return 0;
}
