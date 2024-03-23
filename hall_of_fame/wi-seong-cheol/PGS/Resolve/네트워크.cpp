//
//  네트워크.cpp
//  main
//
//  Created by wi_seong on 3/19/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Level 3
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;
bool vis[201];
vector<int> adj[201];

void dfs(int cur) {
    vis[cur] = true;
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(computers[i][j] == 0) continue;
            adj[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(i);
        answer++;
    }

    return answer;
}
