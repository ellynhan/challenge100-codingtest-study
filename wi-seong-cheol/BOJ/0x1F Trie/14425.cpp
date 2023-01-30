//
//  14425.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 11
 baekjoononlinejudge
 startlink
 codeplus
 sundaycoding
 codingsh
 baekjoon
 codeplus
 codeminus
 startlink
 starlink
 sundaycoding
 codingsh
 codinghs
 sondaycoding
 startrink
 icerink
 [Output]
 4
 */
// 시간복잡도: O(|n| * |m|)
// 최악시간: 5,000,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14425

#include <iostream>
#include <algorithm>

using namespace std;
const int ROOT = 1;
const int MX = 10000 * 500 + 1;
int unused = 2;
bool chk[MX];
int nxt[MX][26];
int n, m;

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    
    cin >> n >> m;
    while(n--) {
        string s; cin >> s;
        insert(s);
    }
    
    int ans = 0;
    while(m--) {
        string s; cin >> s;
        ans += find(s);
    }
    cout << ans;
    
    return 0;
}
