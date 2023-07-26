//
//  10866.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 15
 push_back 1
 push_front 2
 front
 back
 size
 empty
 pop_front
 pop_back
 pop_front
 size
 empty
 pop_back
 push_front 3
 empty
 front
 [Output]
 2
 1
 2
 0
 2
 1
 -1
 0
 1
 -1
 0
 3
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/10886

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >>t;
    deque<int> dq;
    
    while(t--) {
        string op; cin >> op;
        if(op == "push_front") {
            int x; cin >> x;
            dq.push_front(x);
        } else if(op == "push_back") {
            int x; cin >> x;
            dq.push_back(x);
        } else if(op == "pop_front") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if(op == "pop_back") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if(op == "size") {
            cout << dq.size() << '\n';
        } else if(op == "empty") {
            cout << dq.empty() << '\n';
        } else if(op == "front") {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        } else {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
    }
    
    return 0;
}
