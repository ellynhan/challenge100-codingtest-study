#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    stack<char> st;
    string msg;
    getline(cin, msg);

    bool stacking = true;

    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == '<') {
            stacking = false;
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << msg[i];
        }
        if (msg[i] == '>') {
            stacking = true;
            cout << msg[i];
        }
        if (msg[i] >= '0' && msg[i] <= '9') {
            if (stacking) {
                st.push(msg[i]);
            }
            else {
                cout << msg[i];
            }
        }
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            if (stacking) {
                st.push(msg[i]);
            }
            else {
                cout << msg[i];
            }
        }

        if (msg[i] == ' ') {
            if (stacking) {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
            cout << msg[i];
        }

    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << '\n';

    return 0;
}
