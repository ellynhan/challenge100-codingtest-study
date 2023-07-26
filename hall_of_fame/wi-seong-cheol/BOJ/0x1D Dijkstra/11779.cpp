//
//  11779.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 8
 1 2 2
 1 3 3
 1 4 1
 1 5 10
 2 4 2
 3 4 1
 3 5 1
 4 5 3
 1 5
 [Output]
 4
 3
 1 3 5
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11779

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
const int INF = 1e9 + 10;
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int v, e, st, en;
int a, b, w;
int d[1001];
int pre[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    fill(d, d + v + 1, INF);
    while(e--) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    cin >> st >> en;
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }
    cout << d[en] << '\n';
    vector<int> path;
    int cur = en;
    while(cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(int x: path) cout << x << ' ';
    
    return 0;
}
