//
//  17471.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 6
 5 2 3 4 1 2
 2 2 4
 4 1 3 6 5
 2 4 2
 2 1 3
 1 2
 1 2
 [Output]
 6
 5 2 3 4 1 2
 2 2 4
 4 1 3 6 5
 2 4 2
 2 1 3
 1 2
 1 2
 */
// 시간복잡도: O((V + E) ^ 2)
// 최악시간:
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17471

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 11;
const int INF = 0x7f7f7f7f;
int ans = INF;
int n, m, neighbor;
int population[MAX];
int adj[MAX][MAX];
bool isused[MAX];
bool selected[MAX];

bool isPossible(vector<int>& v) {
    // 선거구에 포함된 구역들이 모두 연결되어 있는지 확인
    queue<int> Q;
    bool vis[MAX] = { false };
    Q.push(v[0]);
    vis[v[0]] = true;

    int cnt = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i = 1; i <= n; i++) {
            if (adj[cur][i] && !vis[i] && selected[i] == selected[cur]) {
                vis[i] = true;
                Q.push(i);
                cnt++;
            }
        }
    }

    return (cnt == v.size());
}

void dfs(int cur, int cnt) {
    if (cnt == n) return;
    
    if (cur == n) {
        vector<int> group1, group2;
        for (int i = 1; i <= n; i++) {
            if (selected[i]) group1.push_back(i);
            else group2.push_back(i);
        }
        
        // 두 선거구에 포함된 구역들이 모두 연결되어 있으면 정답 갱신
        if (group1.size() <= 0 || group2.size() <= 0) return;
        if (!isPossible(group1) || !isPossible(group2)) return;
        
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < group1.size(); i++) sum1 += population[group1[i]];
        for (int i = 0; i < group2.size(); i++) sum2 += population[group2[i]];
        ans = min(ans, abs(sum1 - sum2));
        
        return;
    }
    
    selected[cur] = true;
    dfs(cur + 1, cnt + 1);
    selected[cur] = false;
    dfs(cur + 1, cnt + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> population[i];
    for (int i = 1; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> neighbor;
            adj[i][neighbor] = 1;
        }
    }
    
    dfs(1, 0);
    
    if (ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
