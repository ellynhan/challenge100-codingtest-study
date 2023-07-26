#include <iostream>
#include <deque>
#include <queue>

using namespace std;
using ll=long long;

deque<ll> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    bool is_error = false;
    bool direction = true;

    string op;
    cin >> op;

    int n;
    cin >> n;

    string arr;
    cin >> arr;

    if (arr != "[]") {
      ll tmp = 0;
      for (int i = 1; i < arr.size(); i++) {
        char c = arr[i];

        if (c >= '0' && c <= '9') {
          tmp *= 10;
          tmp += (c - '0');
        }

        if (c == ',' || c == ']') {
          q.push_back(tmp);
          tmp = 0;
        }
      }
    }

    for (auto op_c: op) {
      if (op_c == 'R') {
        direction = !direction;
      }

      if (op_c == 'D') {
        if (!q.empty()) {
          if (direction == true) {
            q.pop_front();
          } else {
            q.pop_back();
          }
        } else {
          is_error = true;
        }
      }
    }

    if (is_error) {
      cout << "error" << '\n';
    } else {
      cout << '[';
      if (direction == true) {
        while (!q.empty()) {
          if (q.size() == 1) {
            cout << q.front();
          } else {
            cout << q.front() << ',';
          }
          q.pop_front();
        }
      } else {
        while (!q.empty()) {
          if (q.size() == 1) {
            cout << q.back();
          } else {
            cout << q.back() << ',';
          }
          q.pop_back();
        }
      }
      cout << ']' << '\n';
    }
  }
  return 0;
}
