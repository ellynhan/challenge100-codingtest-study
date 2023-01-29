//
//  16916.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/29.
//

/*
 [Input]
 baekjoon
 aek
 [Output]
 1
 */
// 시간복잡도: O(n + m)
// 최악시간: n + m
// 난이도: Bronze 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16916

#include <iostream>
#include <vector>

using namespace std;
string s, p;
vector<int> f;

vector<int> failure(string& s) {
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
    f = failure(p);
    int j = 0;
    for(int x: f)
        cout << x << ' ';
    for(int i = 0; i < s.size(); i++) {
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
