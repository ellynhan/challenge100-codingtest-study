//
//  [카카오 인턴] 동굴 탐험.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(N + L)
// 최악시간: 350,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/67260

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
const int MXN = 200001;
int N;
vector<int> adj[MXN];
unordered_set<int> s;
int inDeg[MXN], outDeg[MXN];

bool typologySort(const vector<vector<int>>& order) {
    if(inDeg[0] != 0) return false;

    queue<int> Q;
    vector<bool> vis(N, false);
    vector<bool> result(N, false);
    vis[0] = true;
    Q.push(0);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        result[cur] = true;
        inDeg[outDeg[cur]] = 0;

        if(s.find(outDeg[cur]) != s.end()) {
            s.erase(outDeg[cur]);
            Q.push(outDeg[cur]);
            vis[outDeg[cur]] = false;
        }

        for(int nxt: adj[cur]) {
            if(vis[nxt]) continue;
            if(inDeg[nxt] != 0) {
                s.insert(nxt);
                continue;
            }
            vis[nxt] = true;
            Q.push(nxt);
        }
    }

    for(bool val: result)
        if(!val) return false;
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    N = n;

    for(auto p: path) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    for(auto o: order) {
        outDeg[o[0]] = o[1];
        inDeg[o[1]] = o[0];
    }

    bool answer = typologySort(order);

    return answer;
}
