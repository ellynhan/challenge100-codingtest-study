//
//  2504.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 (()[[]])([])
 [Output]
 28
 */
// 시간복잡도: O(n)
// 최악시간: 30
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2504

#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s;
stack<char> S;
int ans;
int num = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            num *= 2;
            S.push(s[i]);
        } else if(s[i] == '[') {
            num *= 3;
            S.push(s[i]);
        } else if(s[i] == ')') {
            if(S.empty() || S.top() != '(') {
                S.push(s[i]);
                break;
            }
            if(s[i - 1] == '(') ans += num;
            S.pop();
            num /= 2;
        } else if(s[i] == ']') {
            if(S.empty() || S.top() != '[') {
                S.push(s[i]);
                break;
            }
            if(s[i - 1] == '[') ans += num;
            S.pop();
            num /= 3;
        }
    }
    if(S.empty()) cout << ans;
    else cout << 0;
    
    return 0;
}
