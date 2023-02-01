//
//  1854.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 10 2
 1 2 2
 1 3 7
 1 4 5
 1 5 6
 2 4 2
 2 3 4
 3 4 6
 3 5 8
 5 2 4
 5 4 1
 [Output]
 -1
 10
 7
 5
 14
 */
// 시간복잡도: O()
// 최악시간:
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1854

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m, k, u, v, w;
priority_queue<int> d[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
    d[1].push(0);
    pq.push({d[1].top(), 1});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        for(auto nxt: adj[cur.Y]) {
            if(d[nxt.X].size() < k || d[nxt.X].top() > cur.X + nxt.Y) {
                if (d[nxt.X].size() == k) d[nxt.X].pop();
                d[nxt.X].push(cur.X + nxt.Y);
                pq.push({cur.X + nxt.Y, nxt.X});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    solve();

    for (int i = 1; i <= n; i++) {
        if(d[i].size() < k) cout << -1 << '\n';
        else cout << d[i].top() << '\n';
    }

    return 0;
}
