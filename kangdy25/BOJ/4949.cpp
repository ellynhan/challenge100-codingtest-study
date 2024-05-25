// 균형잡힌 세상 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "";

    while (true) {
        bool check = true;
        getline(cin, s);
        stack<char> st;

        if (s[0] == '.') {
            break;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    cout << "no\n";
                    check = false;
                    break;
                }
            }
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    cout << "no\n";
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            if (st.empty()) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
    }
}