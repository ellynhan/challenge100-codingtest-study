#include <iostream>
#include <stack>

using namespace std;

int ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    stack<char> st;

    string line;
    cin >> line;

    for (int i = 0; i < line.size(); i++) {
      char c = line[i];

      if (st.empty()) st.push(c);
      else {
          if (st.top() != c) st.push(c);
          else st.pop();
      }
    }

    if (st.empty()) ans += 1;
  }

  cout << ans << '\n';

  return 0;
}
