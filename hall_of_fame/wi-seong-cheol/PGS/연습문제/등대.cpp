//
//  등대.cpp
//  main
//
//  Created by wi_seong on 2/6/24.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/133500

#include <iostream>
#include <vector>

using namespace std;
const int MXN = 100001;
int answer;
vector<int> adj[MXN];
bool isTurnOn[MXN];

void dfs(int cur, int parent) {
    for(int nxt: adj[cur]) {
        if(nxt == parent) continue;
        dfs(nxt, cur);
        if(!isTurnOn[nxt] && !isTurnOn[cur]) {
            isTurnOn[cur] = true;
            answer++;
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    if(n == 2) return 1;

    for(auto element: lighthouse) {
        adj[element[0]].push_back(element[1]);
        adj[element[1]].push_back(element[0]);
    }

    dfs(1, 0);

    return answer;
}
