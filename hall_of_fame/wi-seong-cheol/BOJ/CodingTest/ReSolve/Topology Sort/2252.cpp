//
//  2252.cpp
//  main
//
//  Created by wi_seong on 3/22/24.
//

/*
 [Input]
 3 2
 1 3
 2 3
 [Output]
 1 2 3
 */
// 시간복잡도: O(n)
// 최악시간: 32,000
// 난이도: Gold 3
// Timer: 6m
// Url: https://www.acmicpc.net/problem/2252

#include <iostream>
#include <queue>

using namespace std;
int n, m;
vector<int> adj[32001];
int indeg[32001];

void solve() {
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';

        for(int nxt: adj[cur]) {
            indeg[nxt]--;
            if(indeg[nxt] == 0) {
                Q.push(nxt);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    solve();

	return 0;
}
