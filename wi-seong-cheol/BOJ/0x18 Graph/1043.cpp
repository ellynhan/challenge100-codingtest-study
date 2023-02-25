//
//  1043.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 3
 0
 2 1 2
 1 3
 3 2 3 4
 [Output]
 3
 */
// 시간복잡도: O(n*m)
// 최악시간: 2,500
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, t;
vector<int> adj[51];
vector<int> pt[51];
bool tr[51];

void bfs() {
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        if(tr[i]) Q.push(i);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(tr[nxt]) continue;
            tr[nxt] = 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> t;
    while(t--) {
        int x; cin >> x;
        tr[x] = 1;
    }
    
    for(int i = 0; i < m; i++) {
        int no; cin >> no;
        
        int prv, nxt;
        cin >> prv;
        pt[i].push_back(prv);
        
        while(--no) {
            cin >> nxt;
            pt[i].push_back(nxt);
            adj[nxt].push_back(prv);
            adj[prv].push_back(nxt);
            swap(prv, nxt);
        }
    }
    bfs();
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        bool known = 0;
        for(int p : pt[i])
            if(tr[p]) known = 1;
        if(!known) cnt++;
    }
    cout << cnt;
    
    return 0;
}
