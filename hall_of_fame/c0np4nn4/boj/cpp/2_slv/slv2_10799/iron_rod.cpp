#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
int ans;

char prev_char = '.';

int main() {
  string bar;
  getline(cin, bar);

  for (auto c: bar) {
    if (c == '(') {
      st.push(c);
      prev_char = '(';
    }
    else if (c == ')') {
        if (prev_char == '(') {
          // cout << "[+] ans += " << st.size() - 1 << endl;
          ans += st.size() - 1;
        }
        else {
          // cout << "[+] ans += " << 1 << " (end of the bar)" << endl;
          ans += 1;
        }
        st.pop();
        prev_char = ')';
    }

  }

  cout << ans << endl;
  return 0;
}
