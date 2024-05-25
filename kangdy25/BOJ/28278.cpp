// 스택 2 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, cmd, x;
    cin >> N;
    stack<int> s;
    
    while(N--) {
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                if (s.empty()) {
                    cout << "-1\n";
                } else {
                    cout << s.top() << "\n";
                    s.pop();
                }
                break;
            case 3:
                cout << s.size() << "\n";
                break;
            case 4:
                if (s.empty()) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
                break;
            case 5:
                if (s.empty()) {
                    cout << "-1\n";
                } else {
                    cout << s.top() << "\n";
                }
                break;
            default: // do nothing
                break; 
        }
    }
}