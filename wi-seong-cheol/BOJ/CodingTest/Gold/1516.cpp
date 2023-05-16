//
//  1516.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 5
 10 -1
 10 1 -1
 4 1 -1
 4 3 1 -1
 3 3 -1
 [Output]
 10
 20
 14
 18
 17
 */
// 시간복잡도: O(V + E)
// 최악시간: 1,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1516

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, pre;
vector<int> adj[501];   // 먼저 지어야할 건물 번호
int build[501];         // 짓는데 걸리는 시간
int deg[501];           // 진입차수
int result[501];

void topology() {
    queue<int> Q;
    
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) {
            Q.push(i);
            result[i] = build[i];
        }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(--deg[nxt] == 0)
                Q.push(nxt);
            result[nxt] = max(result[nxt], result[cur] + build[nxt]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> build[i];
        while(1) {
            cin >> pre;
            if(pre == -1) break;
            adj[pre].push_back(i);
            deg[i]++;
        }
    }
    topology();
    for(int i = 1; i <= n; i++)
        cout << result[i] << '\n';
    
    return 0;
}
