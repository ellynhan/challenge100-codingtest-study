//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 10 1 10 2 1
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 1000000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int SIZE = 1000001;
int F, S, G, U, D;
int dist[SIZE];

bool OOB(int x) { return x <= 0 || x > F; }

void bfs() {
    queue<int> Q;
    Q.push(S);
    dist[S] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == G) break;
        for(auto nx: {cur + U, cur - D}) {
            if(OOB(nx) || dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F >> S >> G >> U >> D;
    fill(dist, dist + F + 1, -1);
    bfs();
    
    if(dist[G] == -1) cout << "use the stairs";
    else cout << dist[G];
    
    return 0;
}
