//
//  1305.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10
 abcaabcaab
 [Output]
 4
 */
// 시간복잡도: O(2L)
// 최악시간: 2,000,000
// 난이도: Platinum 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1305

#include <iostream>
#include <vector>

using namespace std;
int n;
string s;
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
    
    cin >> n >> s;
    f = failure(s);
    cout << n - f[n - 1];
    
    return 0;
}
