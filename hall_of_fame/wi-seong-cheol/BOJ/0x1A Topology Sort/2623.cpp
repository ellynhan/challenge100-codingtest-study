//
//  2623.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 3
 3 1 4 3
 4 6 2 5 4
 2 2 3
 [Output]
 1
 6
 2
 5
 4
 3
 */
// 시간복잡도: O(n + m)
// 최악시간: 100,000,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2623

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, k, a, b;
vector<int> adj[1001];
vector<int> result;
int deg[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> k >> a;
        for(int j = 0; j < k - 1; j++) {
            cin >> b;
            adj[a].push_back(b);
            deg[b]++;
            a = b;
        }
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        result.push_back(cur);
        for(int nxt: adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }
    if(result.size() != n) cout << 0;
    else {
        for(int x: result)
            cout << x << '\n';
    }
    
    return 0;
}
