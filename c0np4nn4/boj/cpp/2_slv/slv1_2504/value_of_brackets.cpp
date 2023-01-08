#include <iostream>
#include <stack>

using namespace std;

int sum;
int inner_sum[16];
stack<char> st;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string line;
  cin >> line;

  for (int i = 0; i < line.size(); i++) {
    char c = line[i];

    if (c == '(') {
      st.push(c);
    }
    if (c == '[') {
      st.push(c);
    }
    if (c == ')') {
      if (st.empty()) {
        sum = 0;
        break;
      }

      if (st.top() != '(') {
        sum = 0;
        break;
      }

      if (inner_sum[st.size() + 1] != 0) {
        // cout << "double" << endl;
        inner_sum[st.size()] += inner_sum[st.size() + 1] * 2;
      } else {
        // cout << "+2" << endl;
        inner_sum[st.size()] += 2;
      }

      inner_sum[st.size() + 1] = 0;

      st.pop();

      if (st.empty()) sum = inner_sum[1];
    }
    if (c == ']') {
      if (st.empty()) {
        sum = 0;
        break;
      }
      if (st.top() != '[') {
        sum = 0;
        break;
      }

      if (inner_sum[st.size() + 1] != 0) {
        // cout << "triple" << endl;
        inner_sum[st.size()] += inner_sum[st.size() + 1] * 3;
      } else {
        // cout << "+3" << endl;
        inner_sum[st.size()] += 3;
      }

      inner_sum[st.size() + 1] = 0;

      st.pop();

      if (st.empty()) sum = inner_sum[1];
    }
  }

  cout << sum << '\n';

  return 0;
}

