//
//  10799.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/* 
 [Input]
 ()(((()())(())()))(())
 [Output]
 17
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 7m
// Url: https://www.acmicpc.net/problem/10799

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    stack<char> S;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') S.push(s[i]);
        else {
            if(s[i - 1] == '(') {
                S.pop();
                ans += S.size();
            } else {
                ans++;
                S.pop();
            }
        }
    }
    cout << ans;
    
    return 0;
}
