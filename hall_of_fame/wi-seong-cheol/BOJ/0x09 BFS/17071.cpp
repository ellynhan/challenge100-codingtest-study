//
//  17071.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 27297 339652
 [Output]
 425
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17071

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define X first
#define Y second
const int MAX = 500'000;
int n, m;
int vis[2][MAX + 1];

void bfs() {
    queue<pair<int, int>> Q;
    Q.push({n, 0});
    vis[0][n] = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int nv: {cur.X - 1, cur.X + 1, cur.X * 2}) {
            int nt = cur.Y + 1;
            if(nv < 0 || nv > MAX || vis[nt % 2][nv] != -1) continue;
            vis[nt % 2][nv] = nt;
            Q.push({nv, nt});
        }
    }
}

int move() {
    int time = 0;
    while(m <= MAX) {
        if(vis[time % 2][m] <= time) {
            return time;
        }
        m += ++time;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0 ; i < 2; i++)
        fill(vis[i], vis[i] + MAX + 1, -1);
    bfs();
    cout << move();
    
    return 0;
}
