//
//  18258.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 15
 push 1
 push 2
 front
 back
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
 front
 [Output]
 1
 2
 2
 0
 1
 2
 -1
 0
 1
 -1
 0
 3
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Silver 4
// Timer: 3m
// Url: https://www.acmicpc.net/problem/18256

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    queue<int> Q;
    
    while(t--) {
        string op; cin >>op;
        if(op == "push") {
            int x; cin >> x;
            Q.push(x);
        } else if(op == "pop") {
            if(Q.empty()) cout << "-1\n";
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if(op == "size") {
            cout << Q.size() << '\n';
        } else if(op == "empty") {
            cout << Q.empty() << '\n';
        } else if(op == "front") {
            if(Q.empty()) cout << "-1\n";
            else cout << Q.front() << '\n';
        } else {
            if(Q.empty()) cout << "-1\n";
            else cout << Q.back() << '\n';
        }
    }
    
    return 0;
}
