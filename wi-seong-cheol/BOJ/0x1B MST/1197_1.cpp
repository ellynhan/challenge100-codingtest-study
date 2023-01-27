//
//  1197_1.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/27.
//

/*
 [Input]
 3 3
 1 2 1
 2 3 2
 1 3 3
 [Output]
 3
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1197

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
int v, e;
int a, b, cost;
int cnt, ans;
vector<pair<int, int>> adj[10001];
bool chk[10001];
priority_queue<tuple<int, int, int>,
vector<tuple<int, int, int>>,
greater<tuple<int, int, int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    
    chk[1] = true;
    for(auto nxt: adj[1])
        pq.push({nxt.X, 1, nxt.Y});
    while(cnt < v - 1) {
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = true;
        cnt++;
        for(auto nxt: adj[b])
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
    }
    cout << ans;
    
    return 0;
}
