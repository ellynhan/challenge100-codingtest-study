//
//  13308.cpp
//  main
//
//  Created by wi_seong on 2/21/24.
//

/*
 [Input]
 4 4
 5 2 4 1
 3 1 3
 1 2 2
 4 3 4
 2 4 15
 [Output]
 28
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Platinum 5
// Timer: 2h
// Url: https://www.acmicpc.net/problem/13308

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, m;
int oil[2501];
ll dp[2501][2501];
vector<pair<int, int>> adj[2501];

ll dijkstra(int st, int en) {
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {st, oil[st]}});
    ll ret = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int here = cur.Y.X;
        ll hereCost = -cur.X;
        int hereOil = cur.Y.Y;

        if(dp[here][hereOil] != -1) continue;
        dp[here][hereOil] = hereCost;

        if(here == en) {
            ret = hereCost;
            break;
        }

        for(auto nxt: adj[here]) {
            int next = nxt.X;
            ll nextCost = nxt.Y * min(hereOil, oil[here]) + hereCost;    //there까지 비용
            int nextOil = min(hereOil, oil[here]);

            if(dp[next][nextOil] == -1 ){
                pq.push(make_pair(-nextCost, make_pair(next, nextOil)));
            }
        }
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> oil[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cout << dijkstra(1, n);

	return 0;
}
