#include <iostream>

using namespace std;

int queue[2000001];
int head, tail;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string op;
    cin >> op;

    if (op == "push") {
      int v;
      cin >> v;

      queue[tail] = v;
      tail++;
    }

    if (op == "pop") {
      if (head == tail) {
        cout << -1 << '\n';
      } else {
        cout << queue[head] << '\n';
        head++;
      }
    }

    if (op == "size") {
      cout << tail - head << '\n';
    }

    if (op == "empty") {
      if (head == tail) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }

    if (op == "front") {
      if (head == tail) {
        cout << -1 << '\n';
      } else {
        cout << queue[head] << '\n';
      }
    }

    if (op == "back") {
      if (head == tail) {
        cout << -1 << '\n';
      } else {
        cout << queue[tail-1] << '\n';
      }
    }
  }

  return 0;
}
