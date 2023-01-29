//
//  16172.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/29.
//

/*
 [Input]
 1q2w3e4r5t6y
 qwerty
 [Output]
 1
 */
// 시간복잡도: O(n + m)
// 최악시간: 400,000
// 난이도: Bronze 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/16172

#include <iostream>
#include <vector>

using namespace std;
string s, p;
vector<int> f;

vector<int> failure() {
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> p;
    f = failure();
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        if('0' <= s[i] && s[i] <= '9') continue;
        while(j > 0 && s[i] != p[j]) j = f[j - 1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
