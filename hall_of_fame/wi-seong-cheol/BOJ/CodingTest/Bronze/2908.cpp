//
//  2908.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 Baekjoon Online Judge
 [Output]
 Onrxwbba Bayvar Whqtr
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Bronze 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2908

#include <iostream>

using namespace std;
string s, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, s);
    for(char ch: s) {
        if('a' <= ch && ch <= 'z') {
            if(ch >= 'n') {
                ans += 'a' + ch - 'n';
            } else {
                ans += ch + 13;
            }
        } else if('A' <= ch && ch <= 'Z') {
            if(ch >= 'N') {
                ans += 'A' + ch - 'N';
            } else {
                ans += ch + 13;
            }
        } else {
            ans += ch;
        }
    }
    cout << ans;
    
    return 0;
}
