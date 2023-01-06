#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

stack<int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string op;
    cin >> op;

    if (op == "push") {
      int x;
      cin >> x;

      st.push(x);
    }

    if (op == "pop") {
      if (st.empty()) {
        cout << -1 << '\n';
      } else {
        cout << st.top() << '\n';
        st.pop();
      }
    }

    if (op == "size") {
      cout << st.size() << '\n';
    }

    if (op == "empty") {
      if (st.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }

    if (op == "top") {
      if (st.empty()) {
        cout << -1 << '\n';
      } else {
        cout << st.top() << '\n';
      }
    }
  }

  return 0;
}
