//
//  1753.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 6
 1
 5 1 1
 1 2 2
 1 3 3
 2 3 4
 2 4 5
 3 4 6
 [Output]
 0
 2
 3
 7
 INF
 */
// 시간복잡도: O(ElogE)
// 최악시간: 1,500,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
const int INF = 1e9 + 10;
int v, e, k;
int a, b, w;
vector<pair<int, int>> adj[20001];
int d[20001];
priority_queue<pair<int, int>,
vector<pair<int, int>>,
greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e >> k;
    fill(d, d + v + 1, INF);
    while(e--) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    
    d[k] = 0;
    pq.push({d[k], k});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for(int i = 1; i <= v; i++) {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    
    return 0;
}
