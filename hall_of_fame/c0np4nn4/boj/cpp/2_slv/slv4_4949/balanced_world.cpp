#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (1) {
    bool is_good = true;
    while (!st.empty()) {
      st.pop();
    }

    string msg;
    getline(cin, msg);

    if (msg == ".") break;

    for (auto c: msg) {
      if (c == '.') break;

      if (c == '(' || c == '[') {
        st.push(c);
      }

      if (c == ')' || c == ']') {
        if (st.empty()) {
          is_good = false;
          break;
        } else {
          if (c == ')') {
            if (st.top() != '(') {
              is_good = false;
              break;
            } else {
              st.pop();
            }
          }
          if (c == ']') {
            if (st.top() != '[') {
              is_good = false;
              break;
            } else {
              st.pop();
            }
          }
        }
      }
    }

    if (!st.empty()) {
      is_good = false;
    }

    if (is_good) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }

  }

  return 0;
}
