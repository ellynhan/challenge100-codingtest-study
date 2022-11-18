//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 1
 5
 3 3 1 1 4
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 10,000,000,000
// 난이도: Gold 3
// Timer: 38m
// Url: https://www.acmicpc.net/problem/9466

#include <iostream>

using namespace std;
const int SIZE = 100001;
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;
int n;
int board[SIZE];
int vis[SIZE];

void bfs(int x) {
    int cur = x;
    while(1) {
        vis[cur] = x;
        cur = board[cur];
        if(vis[cur] == x) {
            while(vis[cur] != CYCLE_IN) {
                vis[cur] = CYCLE_IN;
                cur = board[cur];
            }
            return;
        } else if(vis[cur] != NOT_VISITED) return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        fill(vis, vis + n + 1, NOT_VISITED);
        for(int i = 1; i <= n; i++)
            cin >> board[i];
        for(int i = 1; i <= n; i++)
            if(vis[i] == NOT_VISITED) bfs(i);
        for(int i = 1; i <= n; i++)
            if(vis[i] != CYCLE_IN) ans++;
        cout << ans << '\n';
    }
    
    return 0;
}
