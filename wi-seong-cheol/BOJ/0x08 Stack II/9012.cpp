//
//  9012.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 6
 (())())
 (((()())()
 (()())((()))
 ((()()(()))(((())))()
 ()()()()(()()())()
 (()((())()(
 [Output]
 NO
 NO
 YES
 NO
 YES
 NO
 */
// 시간복잡도: O(n)
// 최악시간: 50 * T
// 난이도: Silver 4
// Timer: 3m
// Url: https://www.acmicpc.net/problem/9012

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n--) {
        stack<char> S;
        string s; cin >> s;
        for(auto ch: s) {
            if(ch == '(') S.push(ch);
            else {
                if(!S.empty() && S.top() == '(') S.pop();
                else {
                    S.push(ch);
                    break;
                }
            }
        }
        if(S.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
