//
//  16118.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 5 6
 1 2 3
 1 3 2
 2 3 2
 2 4 4
 3 5 4
 4 5 3
 [Output]
 1
 */
// 시간복잡도: O(ElogV)
// 최악시간: 300,000
// 난이도: Gold 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/16118

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m, u, v, w, ans;
vector<pair<int, int>> adj[4001];
int d_fox[4001];
int d_wolf[2][4001];

void move_fox() {
    priority_queue<pair<int, int>> pq;
    d_fox[1] = 0;
    pq.push({d_fox[1], 1});
    
    while(!pq.empty()) {
        int cost, cur;
        tie(cost, cur) = pq.top(); pq.pop();
        cost *= -1;
        
        if(d_fox[cur] < cost) continue;
        
        for(auto nxt: adj[cur]) {
            int next = nxt.X;
            int next_cost = cost + nxt.Y;
            if(d_fox[next] <= next_cost) continue;
            d_fox[next] = next_cost;
            pq.push({-next_cost, next});
        }
    }
}

void move_wolf() {
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 1, 1});
    
    while(!pq.empty()){
        int cost, cur, state;
        tie(cost, cur, state) = pq.top(); pq.pop();
        cost *= -1;
        
        if(d_wolf[(state + 1) % 2][cur] < cost) continue;
        
        for(auto nxt: adj[cur]) {
            if(state == 1) {
                int next = nxt.X;
                int next_cost = cost + (nxt.Y / 2);
                
                if(d_wolf[1][next] <= next_cost) continue;
                d_wolf[1][next] = next_cost;
                pq.push({-next_cost, next, 0});
            } else if(state == 0) {
                int next = nxt.X;
                int next_cost = cost + (nxt.Y * 2);
                
                if(d_wolf[0][next] <= next_cost) continue;
                d_wolf[0][next] = next_cost;
                pq.push({-next_cost, next, 1});
            }
        }
    }
}

void init() {
    memset(d_fox, INF, sizeof(d_fox));
    memset(d_wolf, INF, sizeof(d_wolf));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    init();
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w * 2});
        adj[v].push_back({u, w * 2});
    }
    move_fox();
    move_wolf();
    for(int i = 2; i <= n; i++)
        if(d_fox[i] < min(d_wolf[0][i], d_wolf[1][i]))
            ans++;
    cout << ans;
    
    return 0;
}
