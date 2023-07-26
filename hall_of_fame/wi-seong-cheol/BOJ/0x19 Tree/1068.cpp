//
//  1068.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9
 -1 0 0 2 2 4 4 6 6
 4
 [Output]
 2
 */
// 시간복잡도: O(v * e)
// 최악시간:
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>

using namespace std;
int root, n, x, cut, cnt;
vector<int> adj[51];

void dfs(int cur) {
    if(cur == cut) return;
    if(adj[cur].empty()) {
        cnt++;
        return;
    }
    for(int nxt: adj[cur]) {
        if(adj[cur].size() == 1 && nxt == cut) {
            cnt++;
            continue;
        }
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if (x == -1) {
            root = i;
            continue;
        }
        adj[x].push_back(i);
    }
    cin >> cut;
    dfs(root);
    cout << cnt;
    
    return 0;
}
