#include <iostream>

using namespace std;

int n;
int one, zero, neg_one;
int paper[2187][2187];

void init_paper() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }
}

void foo(int n, int x, int y) {
  if (n < 1) return;

  int s = paper[x][y];
  // cout << "\nn: " << n << ", x: " << x << ", y: " << y << ", s: " << s << endl;
  int b = n/3;

  bool all_same = true;

  for (int i = x; (i < x + n) && all_same; i++) {
    for (int j = y; j < y + n; j++) {
      if (paper[i][j] != s) {
        all_same = false;

        // cout << "divide!" << endl;
        foo(b, x, y);
        foo(b, x, y + b * 1);
        foo(b, x, y + b * 2);
        //
        foo(b, x + b * 1, y);
        foo(b, x + b * 1, y + b * 1);
        foo(b, x + b * 1, y + b * 2);
        //
        foo(b, x + b * 2, y);
        foo(b, x + b * 2, y + b * 1);
        foo(b, x + b * 2, y + b * 2);

        break;
      }
    }
  }
  if (all_same) {
    if (s == 1) {
      // cout << "one" << endl;
      one++;
    }
    if (s == 0) {
      // cout << "zero" << endl;
      zero++;
    }
    if (s == -1) {
      // cout << "neg_one" << endl;
      neg_one++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  init_paper();

  foo(n, 0, 0);

  cout << neg_one << '\n';
  cout << zero << '\n';
  cout << one << '\n';

  return 0;
}
