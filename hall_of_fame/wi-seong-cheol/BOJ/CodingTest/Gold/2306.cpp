//
//  2306.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/19.
//

/*
 [Input]
 aattgatc
 [Output]
 8
 */
// 시간복잡도: O(n)
// 최악시간: 500
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2306

#include <iostream>
#include <cstring>

using namespace std;
string s;
int d[501][501];

int solve(int l, int r) {
    if(l >= r) return 0;
    
    int& ret = d[l][r];
    if(ret != -1) return ret;
    
    for(int i = l; i < r; i++)
        ret = max(ret, solve(l, i) + solve(i + 1, r));
    
    if((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
        ret = max(ret, solve(l + 1, r - 1) + 2);
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> s;
    cout << solve(0, int(s.length()) - 1);
    
    return 0;
}
