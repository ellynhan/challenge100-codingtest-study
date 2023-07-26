//
//  매출 하락 최소화.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/01.
//

// 시간복잡도: O(E + V)
// 최악시간: 600,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/72416

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
const ll INF = 0x7fffffff7ffffff;
const int MX = 300001;
vector<int> adj[MX];
vector<int> s;
ll d[MX][2];

void dfs(int cur) {
    if(adj[cur].empty()) {
        d[cur][0] = s[cur];
        d[cur][1] = 0;
        return;
    }
    ll mingap = INF;
    d[cur][0] = s[cur];
    for(int nxt: adj[cur]) {
        dfs(nxt);
        d[cur][0] += min(d[nxt][0], d[nxt][1]);
        mingap = min(mingap, d[nxt][0] - d[nxt][1]);
    }
    if(mingap < 0) mingap = 0;
    d[cur][1] = d[cur][0] + mingap - s[cur];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    s.push_back(0);
    for(auto x : sales) s.push_back(x);
    for(auto x : links)
        adj[x[0]].push_back(x[1]);
    dfs(1);
    return min(d[1][0],d[1][1]);
}
