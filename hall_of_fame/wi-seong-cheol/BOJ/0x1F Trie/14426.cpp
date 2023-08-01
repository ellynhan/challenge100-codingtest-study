//
//  14426.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 10
 baekjoononlinejudge
 startlink
 codeplus
 sundaycoding
 codingsh
 baekjoon
 star
 start
 code
 sunday
 coding
 cod
 online
 judge
 plus
 [Output]
 7
 */
// 시간복잡도: O(m * l)
// 최악시간: 500,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14426

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 10000 * 500 + 1;
const int ROOT = 1;
int n, m, ans;
string s;
int unused = 2;
int nxt[MX][26];

int ctoi(char c) {
    return c - 'a';
}

void insert(const string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
}

bool find(const string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            return false;
        cur = nxt[cur][ctoi(c)];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    cin >> n >> m;
    while(n--) {
        cin >> s;
        insert(s);
    }
    while(m--) {
        cin >> s;
        ans += find(s);
    }
    cout << ans;
    
    return 0;
}
