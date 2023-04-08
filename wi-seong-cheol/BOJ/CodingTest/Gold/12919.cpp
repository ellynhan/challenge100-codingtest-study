//
//  12919.cpp
//  main
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 A
 BABA
 [Output]
 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/12919

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
bool flag;
string s, t;

void solve(string& str) {
    if(flag) return;
    if(str.length() == s.length()) {
        if(str == s) flag = true;
        return;
    }
    
    if(str.back() == 'A') {
        string tmp = str;
        tmp.pop_back();
        solve(tmp);
    }
    if(str.front() == 'B') {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        solve(tmp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> t;
    solve(t);
    cout << flag;
    
    return 0;
}
