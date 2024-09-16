// 덱 2 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, cmd, num;
    cin >> N;
    deque<int> dq;
    
    while(N--) {
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> num;
                dq.push_front(num);
                break;
            case 2:
                cin >> num;
                dq.push_back(num);
                break;
            case 3:
                if (!dq.empty()) {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                } else {
                    cout << "-1\n";
                }
                break;
            case 4:
                if (!dq.empty()) {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                } else {
                    cout << "-1\n";
                }
                break;
            case 5:
                cout << dq.size() << "\n";
                break;
            case 6:
                if (!dq.empty()) {
                    cout << "0\n";
                } else {
                    cout << "1\n";
                }
                break;
            case 7:
                if (!dq.empty()) {
                    cout << dq.front() << "\n";
                } else {
                    cout << "-1\n";
                }
                break;
            case 8:
                if (!dq.empty()) {
                    cout << dq.back() << "\n";
                } else {
                    cout << "-1\n";
                }
                break;
            default:
                break;
        }
    }
}