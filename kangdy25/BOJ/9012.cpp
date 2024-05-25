// 괄호 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string s;

    while (N--) {
        bool check = true;
        cin >> s;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    cout << "NO\n";
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            if (st.empty()) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }

        }
    }
}