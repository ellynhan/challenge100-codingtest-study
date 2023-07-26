//
//  2216.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/20.
//

/*
 [Input]
 10 -1 -5
 abc
 dc
 [Output]
 7
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 9,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2216

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = -1e9;
int a, b, c;
string s1, s2;
int d[3001][3001];

int solve(int n, int m) {
    if(n == s1.size())
        return ((int)s2.size() - m) * b;
    if(m == s2.size())
        return ((int)s1.size() - n) * b;
    
    int& ret = d[n][m];
    if(ret != INF) return ret;
    ret = b + max(solve(n + 1, m), solve(n, m + 1));
    ret = max(ret, (s1[n] == s2[m] ? a : c) + solve(n + 1, m + 1));
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 3001; i++)
        fill(d[i], d[i] + 3001, INF);
    cin >> a >> b >> c;
    cin >> s1 >> s2;
    cout << solve(0, 0);
    
    return 0;
}
