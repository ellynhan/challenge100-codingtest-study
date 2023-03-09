//
//  3665.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 3
 5
 5 4 3 2 1
 2
 2 4
 3 4
 3
 2 3 1
 0
 4
 1 2 3 4
 3
 1 2
 3 4
 2 3
 [Output]
 5 3 2 4 1
 2 3 1
 IMPOSSIBLE
 */
// 시간복잡도: O(O(V + E)
// 최악시간: 1,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3665

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int t, n, m, x, f, s;
bool adj[501][501];
int team[501];
int order[501];
int deg[501];
vector<int> answer;

int topology() {
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) Q.push(i);
    
    while(!Q.empty()) {
        if(Q.size() > 1) return 0;
        int cur = Q.front(); Q.pop();
        
        answer.push_back(team[cur]);
        if(answer.size() == n) return 1;
        
        for(int i = 1; i <= n; i++) {
            if(!adj[cur][i]) continue;
            adj[cur][i] = false;
            deg[i]--;
            if(deg[i] == 0) Q.push(i);
        }
    }
    
    return -1;
}

void init() {
    answer.clear();
    memset(adj, 0, sizeof(adj));
    memset(team, 0, sizeof(team));
    memset(order, 0, sizeof(order));
    memset(deg, 0, sizeof(deg));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        init();
        for(int i = 1; i <= n; i++) {
            cin >> team[i];
            order[team[i]] = i;
        }
            
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                adj[i][j] = true;
                deg[j]++;
            }
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> f >> s;
            
            if(order[f] > order[s]) swap(f, s);
            int node_f = order[f], node_s = order[s];
            
            adj[node_f][node_s] = false;
            deg[node_s]--;
            
            adj[node_s][node_f] = true;
            deg[node_f]++;
        }
        int result = topology();
        if(result == -1) cout << "IMPOSSIBLE\n";
        else if(result == 0) cout << "?\n";
        else {
            for(int num: answer)
                cout << num << ' ';
            printf("\n");
        }
    }
    
    return 0;
}
