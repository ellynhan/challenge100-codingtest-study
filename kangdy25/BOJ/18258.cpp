// 큐 2 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num;
    string s;
    queue<int> q;
    cin >> N;
    
    while(N--) {
        cin >> s;
        if (s == "push") {
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            } else {
                cout << "-1\n";
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            if (q.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }
        }    
    }
}