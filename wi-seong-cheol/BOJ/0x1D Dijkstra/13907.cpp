//
//  13907.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 3 2
 1 3
 1 3 5
 1 2 1
 2 3 2
 1
 2
 [Output]
 3
 5
 8
 */
// 시간복잡도: O(nk)
// 최악시간: 30,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13907

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 0x3f3f3f3f
struct info {
    int idx, cnt, val;
};
struct cmp{
    bool operator()(const info &a, const info &b){
        return a.val > b.val;
    }
};
int n, m, k, st, en, u, v, w, mul, val, sum;
vector<info> adj[1001];
priority_queue<info, vector<info>, cmp> pq;
int d[1001][1001];

int cal() {
    int result = INF;
    
    for(int i = 1; i < n; i++) {
        int vv = d[en][i] + i * sum;
        result = min(result, vv);
    }
    
    return result;
}

void dijkstra() {
    for(int i = 1; i < n + 1; i++)
        fill(d[i], d[i] + n, INF);
    pq.push({st, 0, 0});
    d[st][0] = 0;
    while(!pq.empty()) {
        auto [cidx, cc, cv] = pq.top(); pq.pop();
        if(d[cidx][cc] < cv) continue;
        for(auto nxt: adj[cidx]) {
            int next = nxt.idx;
            int nv = nxt.val;
            if(d[next][cc + 1] <= cv + nv) continue;
            d[next][cc + 1] = cv + nv;
            pq.push({next, cc + 1, cv + nv});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k >> st >> en;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, 0, w});
        adj[v].push_back({u, 0, w});
    }
    dijkstra();
    
    cout << cal() << '\n';
    for(int i = 0; i < k; i++) {
        cin >> val;
        sum += val;
        cout << cal() << '\n';
    }
    
    return 0;
}
