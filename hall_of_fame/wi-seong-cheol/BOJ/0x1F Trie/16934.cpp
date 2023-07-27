//
//  16934.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 baekjoon
 startlink
 bakejoon
 beakjoon
 baekjoon
 [Output]
 b
 s
 bak
 be
 baekjoon2
 */
// 시간복잡도: O(M * L)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/16934

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 100'000 * 10 + 1;
const int ROOT = 1;
int n;
string s;
int unused = ROOT + 1;
int nxt[MX][26];
int chk[MX];

int ctoi(char c) {
    return c - 'a';
}

string insert(string& s) {
    int cur = ROOT;
    string ans = "";
    bool isvalid = true;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1) {
            nxt[cur][ctoi(c)] = unused++;
            if(isvalid) ans += c;
            isvalid = false;
        }
        if(isvalid) ans += c;
        cur = nxt[cur][ctoi(c)];
    }
    if(chk[cur] == 0) {
        chk[cur]++;
    } else {
        chk[cur]++;
        ans += to_string(chk[cur]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    cin >> n;
    while(n--) {
        cin >> s;
        cout << insert(s) << '\n';
    }
    
    return 0;
}
