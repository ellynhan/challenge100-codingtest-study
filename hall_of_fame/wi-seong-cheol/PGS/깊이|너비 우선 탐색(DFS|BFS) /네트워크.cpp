//
//  네트워크.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 40,000
// 난이도: Level 3
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;
vector<int> adj[201];
bool vis[201];
int N;

void dfs(const vector<vector<int>>& computers, int cur) {
    vis[cur] = true;

    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        dfs(computers, nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(computers[i][j] != 1) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(computers, i);
        answer++;
    }

    return answer;
}
