//
//  2660.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 1 2
 2 3
 3 4
 4 5
 2 4
 5 3
 -1 -1
 [Output]
 2 3
 2 3 4
 */
// 시간복잡도: O(n * m)
// 최악시간: 50 * m
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2660

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, u, v, mx;
vector<int> adj[51];
vector<pair<int, int>> candsc;
int score[52];

int bfs(int st) {
    queue<int> Q;
    int dist[52];
    fill(dist, dist + n + 1, -1);
    Q.push(st);
    dist[st] = 0;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    
    int val = *max_element(dist + 1, dist + n + 1);
    return val == 0 ? 100 : val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(1) {
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        score[i] = bfs(i);
    int mn = *min_element(score + 1, score + n + 1);
    vector<int> cand;
    for(int i = 1; i <= n; i++)
        if(score[i] == mn)
            cand.push_back(i);
    cout << mn << ' ' << cand.size() << '\n';
    for(int c: cand) cout << c << ' ';
    
    return 0;
}
