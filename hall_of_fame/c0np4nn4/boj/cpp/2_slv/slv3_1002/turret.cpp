#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  double x1, y1, r1, x2, y2, r2;

  cin >> t;

  while (t--) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double dist =
        sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

    // cout << "dist: " << dist << endl;
    // cout << "r1: " << r1 << endl;
    // cout << "r2: " << r2 << endl;

    if (x1 == x2 && y1 == y2 && r1 == r2) {
      cout << -1 << '\n';
    } else if (dist == r1 + r2 || dist == abs(r1 - r2)) {
      cout << 1 << '\n';
    } else if (dist > r1 + r2 || dist < abs(r1 - r2)) {
      cout << 0 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }

  return 0;
}
