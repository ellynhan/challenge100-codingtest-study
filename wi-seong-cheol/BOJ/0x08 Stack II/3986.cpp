//
//  3986.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/* 
 [Input]
 3
 ABAB
 AABB
 ABBA
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 4
// Timer: 6m
// Url: https://www.acmicpc.net/problem/3986

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int ans = 0;
    while(n--) {
        stack<char> S;
        string s; cin >> s;
        for(auto ch: s) {
            if(S.empty()) S.push(ch);
            else if(S.top() == ch) S.pop();
            else S.push(ch);
        }
        if(S.empty()) ans++;
    }
    cout << ans;
    
    return 0;
}
