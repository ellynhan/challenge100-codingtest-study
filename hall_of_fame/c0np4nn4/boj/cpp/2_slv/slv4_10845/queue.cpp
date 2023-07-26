#include <iostream>

using namespace std;

int queue[10001];
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
        cout << -1 << endl;
      } else {
        cout << queue[head] << endl;
        head++;
      }
    }

    if (op == "size") {
      cout << tail - head << endl;
    }

    if (op == "empty") {
      if (head == tail) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }

    if (op == "front") {
      if (head == tail) {
        cout << -1 << endl;
      } else {
        cout << queue[head] << endl;
      }
    }

    if (op == "back") {
      if (head == tail) {
        cout << -1 << endl;
      } else {
        cout << queue[tail-1] << endl;
      }
    }
  }

  return 0;
}

