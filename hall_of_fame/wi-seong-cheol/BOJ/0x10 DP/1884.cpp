//
//  1884.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 5
 6
 7
 1 2 2 3
 2 4 3 3
 3 4 2 4
 1 3 4 1
 4 6 2 1
 3 5 2 0
 5 4 3 2
 [Output]
 11
 */
// 시간복잡도: O(n * m * k)
// 최악시간: 100,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1884

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
#define INF 987654321
int k, n, r;
int s, d, l, t;
vector<tuple<int, int, int>> road[101];
int roadCost[101][101];
int dp[101][10001];

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 10001; j++) {
            dp[i][j] = -1;
        }
    }
}

int solve(int st, int cost) {
    if(dp[st][cost] != -1) return dp[st][cost];
    if(st == n) return 0;
    dp[st][cost] = INF;

    for(auto element: road[st]) {
        int next, length, toll;
        tie(next, length, toll) = element;
        if(cost - toll < 0) continue;
        dp[st][cost] = min(dp[st][cost], solve(next, cost - toll) + length);
    }

    return dp[st][cost];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> k >> n >> r;
    init();
    for(int i = 0; i < r; i++) {
        cin >> s >> d >> l >> t;
        road[s].push_back({d, l, t});
    }
    int answer = solve(1, k);

    if(answer == INF) cout << -1;
    else cout << answer;

	return 0;
}
