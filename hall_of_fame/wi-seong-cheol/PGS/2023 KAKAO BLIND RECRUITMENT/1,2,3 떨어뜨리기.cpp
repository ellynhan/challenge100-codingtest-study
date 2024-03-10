//
//  1,2,3 떨어뜨리기.cpp
//  main
//
//  Created by wi_seong on 2/13/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 4
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150364

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> adj[101];

int drop(vector<int> &road) {
    int node = 1;

    while(!adj[node].empty()) {
        int nx = adj[node][road[node]];
        road[node] = (road[node] + 1) % int(adj[node].size());
        node = nx;
    }

    return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    int n = int(target.size());

    for(auto edge: edges)
        adj[edge[0]].push_back(edge[1]);
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    vector<int> road(n + 1, 0), stacked(n + 1, 0), simulation;
    vector<bool> enough(n + 1, 0);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(target[i] <= stacked[i] * 3) {
            enough[i] = 1;
            cnt++;
        }
    }

    while(cnt < n) {
        int x = drop(road) - 1;
        simulation.push_back(x),stacked[x]++;

        if(target[x] < stacked[x]) return {-1};
        if(target[x] <= stacked[x] * 3) {
            if(!enough[x]) {
                cnt++;
                enough[x] = 1;
            }
        }
    }

    for(auto i: simulation) {
        int x = max(1, target[i] - (stacked[i] - 1) * 3);
        target[i] -= x;stacked[i]--;
        answer.push_back(x);
    }

    return answer;
}
