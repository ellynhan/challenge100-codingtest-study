//
//  모두 0으로 만들기.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(E)
// 최악시간: 300,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/76503

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll answer;
vector<int> adj[300001];

void solve(vector<ll>& sum, int cur, int parent) {
    for(int nxt: adj[cur])
        if(nxt != parent)
            solve(sum, nxt, cur);

    sum[parent] += sum[cur];
    answer += abs(sum[cur]);
}

ll solution(vector<int> a, vector<vector<int>> edges) {
    vector<ll> sum;
    for(int x: a)
        sum.push_back(ll(x));

    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    solve(sum, 0, 0);

    if(sum[0] == 0) return answer;
    return -1;
}
