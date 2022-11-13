//
//  7309.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 14
 push 1
 push 2
 top
 size
 empty
 pop
 pop
 pop
 size
 empty
 pop
 push 3
 empty
 top
 [Output]
 2
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
// Timer: 7m
// Url: https://www.acmicpc.net/problem/7309

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    stack<int> S;
    while(t--) {
        string op; cin >> op;
        if(op == "push") {
            int x; cin >> x;
            S.push(x);
        } else if(op == "pop") {
            if(!S.empty()) {
                cout << S.top() << '\n';
                S.pop();
            } else {
                cout << "-1\n";
            }
        } else if(op == "size") {
            cout << S.size() << '\n';
        } else if(op == "top") {
            if(!S.empty()) {
                cout << S.top() << '\n';
            } else {
                cout << "-1\n";
            }
        } else {
            if(!S.empty()) cout << "0\n";
            else cout << "1\n";
        }
    }
    return 0;
}
