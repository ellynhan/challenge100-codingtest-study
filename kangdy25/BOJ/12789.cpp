// 도키도키 간식드리미 / 실버 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num, cnt = 1;
    cin >> N;
    stack<int> st;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == cnt) {
            cnt++;
        } else {
            st.push(num);
        }

        while(!st.empty() && st.top() == cnt) {
            st.pop();
            cnt++;
        }
    }
    if (st.empty()) {
        cout << "Nice\n";
    } else {
        cout << "Sad\n";
    }
}