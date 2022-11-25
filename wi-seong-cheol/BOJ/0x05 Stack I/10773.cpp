//
//  10773.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 4
 3
 0
 4
 0
 [Output]
 0
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 3m
// Url: https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    int ans = 0;
    stack<int> S;
    while(t--) {
        int x; cin >> x;
        if(x == 0) S.pop();
        else S.push(x);
    }
    while(!S.empty()) {
        ans += S.top();
        S.pop();
    }
    cout << ans;
    
    return 0;
}
