//
//  GALLERY.cpp
//  main
//
//  Created by wi_seong on 1/25/24.
//

/*
 [Input]
 3
 6 5
 0 1
 1 2
 1 3
 2 5
 0 4
 4 2
 0 1
 2 3
 1000 1
 0 1
 [Output]
 3
 2
 999
 */
// 시간복잡도: O(g + h)
// 최악시간: 2,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/GALLERY

#include <iostream>
#include <vector>

using namespace std;
int t, v;
const int MAX_V = 1000;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            ++children[dfs(there)];
        }
    }
    if(children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }
    if(children[INSTALLED]) {
        return WATCHED;
    }
    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(v, false);
    for(int u = 0; u < v; u++) {
        if(!visited[u] && dfs(u) == UNWATCHED) {
            ++installed;
        }
    }
    return installed;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        int g, h;
        cin >> g >> h;
        v = g;
        for(int i = 0; i < g; i++) {
            adj[i].clear();
        }
        for(int i = 0; i < h; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << installCamera() << endl;
    }

	return 0;
}
