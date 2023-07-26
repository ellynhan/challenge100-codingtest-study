//
//  14725.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3
 2 B A
 4 A B C D
 2 A C
 [Output]
 A
 --B
 ----C
 ------D
 --C
 B
 --A
 */
// 시간복잡도: O((M + L) ^ 2)
// 최악시간: 225,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14725

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int MX = 1000 * 15 + 1;
const int ROOT = 1;
int n, k;
string s;
int unused = ROOT + 1;
int depth[MX];
string room[MX];
unordered_map<string, int> nxt[MX];

void insert(vector<string>& route) {
    int v = ROOT;
    for(auto r: route) {
        int nv = nxt[v][r];
        if(nv == 0)
            nv = nxt[v][r] = unused++;
        depth[nv] = depth[v] + 1;
        room[nv] = r;
        v = nv;
    }
}

void dfs(int v) {
    if(v != ROOT) {
        for(int i = 0; i < depth[v]; i++) cout << "--";
        cout << room[v] << '\n';
    }
    vector<pair<string, int>> m(nxt[v].begin(), nxt[v].end());
    sort(m.begin(), m.end());
    for(auto mm: m) dfs(mm.Y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    depth[ROOT] = -1;
    while(n--) {
        cin >> k;
        vector<string> route;
        while(k--) {
            cin >> s;
            route.push_back(s);
        }
        insert(route);
    }
    dfs(ROOT);
    
    return 0;
}
