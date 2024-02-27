//
//  GPS.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 2,000,000
// 난이도: Level 3
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1837

#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int cache[201][10001];
unordered_set<int> adj[201];

int solve(int cur, int k, const vector<int>& gps_log) {
    if(k == int(gps_log.size()) - 1)
        return (gps_log[k] == cur ? 0 : -1);
    int &ret = cache[cur][k];
    if(ret != -1) return ret;
    ret = INF;

    for(int nxt: adj[cur]) {
        int result = solve(nxt, k + 1, gps_log);
        if(result == -1) continue;
        ret = min(ret, result + (gps_log[k] != cur));
    }

    return (ret == INF ? -1 : ret);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = INF;
    memset(cache, -1, sizeof(cache));

    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        adj[i].insert(i);
    }

    for(auto edge: edge_list) {
        adj[edge[0]].insert(edge[1]);
        adj[edge[1]].insert(edge[0]);
    }

    for(int nxt: adj[gps_log[0]]) {
        int result = solve(nxt, 1, gps_log);
        if(result == -1) continue;
        answer = min(answer, result);
    }

    return (answer == INF ? -1 : answer);
}
