//
//  5052.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 3
 911
 97625999
 91125426
 5
 113
 12340
 123440
 12345
 98346
 [Output]
 NO
 YES
 */
// 시간복잡도: O(M * L)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/5052

#include <iostream>
#include <vector>

using namespace std;
const int MX = 10000 * 10 + 1;
const int ROOT = 1;
int t, n;
int unused = 2;
int nxt[MX][10];
int chk[MX];
string s;

int ctoi(char c) {
    return c - '0';
}

bool insert(string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
        if(chk[cur]) return false;
    }
    if(cur != unused - 1) return false;
    chk[cur] = true;
    return true;
}

void init() {
    unused = 2;
    fill(chk, chk + MX, false);
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 10, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        init();
        cin >> n;
        bool isValid = true;
        while(n--) {
            cin >> s;
            if(!insert(s)) isValid = false;
        }
        if(isValid) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
