//
//  PROMISES.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 2
 4 2 2
 0 1 4
 0 3 1
 0 2 2
 1 2 6
 4 2 2
 0 1 4
 0 3 1
 1 2 6
 0 2 2
 [Output]
 1
 0
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/PROMISES

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 987654321;
const int MXN = 201;
int t, V, N, M, u, v, w;
int adj[MXN][MXN];

void init() {
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++) {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
}

bool update(int a, int b, int c) {
    if(adj[a][b] <= c) return false;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            adj[i][j] = min(adj[i][j],
                            min(adj[i][a] + c + adj[b][j],
                                adj[i][b] + c + adj[a][j]));
        }
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> V >> M >> N;
        init();
        for(int i = 0; i < M; i++) {
            cin >> u >> v >> w;
            update(u, v, w);
        }
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cin >> u >> v >> w;
            if(!update(u, v, w)) cnt++;
        }
        cout << cnt << '\n';
    }

	return 0;
}
