//
//  16906.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3
 1 2 3
 [Output]
 1
 0
 10
 110
 */
// 시간복잡도: O(M * L)
// 최악시간: 1,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16906

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int MX = 1001;
const int ROOT = 1;
int n, len, nxt[MX][2], unused = ROOT + 1;
string successStr;
vector<pair<int, int>> v;   // 길이, 순서
map<int, string> m;         // 순서, 문자열
bool chk[MX], success;;

int ctoi(char c) {
    return c - '0';
}

void insert(string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for(char c: s) {
        if(nxt[cur][ctoi(c)] == -1)
            return false;
        cur = nxt[cur][ctoi(c)];
    }
    return chk[cur];
}

// 한 번에 양 쪽으로 갈라짐
void join(int len, string s) {
    if(success) return;
    if(s.size() == len) {
        insert(s);
        success = true;
        successStr = s;
    }
    string s2 = s + '0';
    if(!find(s2)) join(len, s2);
    if(success) return;
    string s3 = s + '1';
    if(!find(s3)) join(len, s3);
}

void init() {
    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 2, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    init();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> len;
        v.push_back({len, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        len = v[i].X;
        success = false;
        join(len, "");
        if(!success) {
            cout << -1;
            return 0;
        }
        m[v[i].Y] = successStr;
    }
    
    cout << "1\n";
    for(int i = 0; i < n; i++)
        cout << m[i] << '\n';
    
    return 0;
}
