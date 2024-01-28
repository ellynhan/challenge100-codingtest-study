//
//  MATCHFIX.cpp
//  main
//
//  Created by wi_seong on 1/28/24.
//

/*
 [Input]
 3
 2 2
 3 3
 0 1
 0 1
 3 3
 4 2 2
 1 2
 1 2
 1 2
 4 4
 5 3 3 2
 0 1
 1 2
 2 3
 1 3
 [Output]
 5
 -1
 5
 */
// 시간복잡도: O(M ^ 2)
// 최악시간: 10,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/MATCHFIX

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int INF = 987654321;
const int MXN = 120;
int t, V, playerNum, matchNum;
int wins[12], match[100][2];
int capacity[MXN][MXN], flow[MXN][MXN];

void init() {
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
}

int networkFlow(int source, int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> parent(V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for(int there = 0; there < V; there++) {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int canWinWith(int maxWin) {
    capacity[2 + matchNum][1] = maxWin - wins[0];

    for(int i = 1; i < playerNum; ++i){
      capacity[2 + matchNum + i][1] = (maxWin - 1) - wins[i];

      if(capacity[2 + matchNum + i][1] < 0)
        return -1;
    }

    return networkFlow(0, 1);
}

int solve(int lower, int upper) {
    int ret = -1;
    int remainFlow = matchNum;
    for(int maxWin = lower; maxWin <= upper; maxWin++) {
        int newWin = canWinWith(maxWin);
        if(newWin == -1) continue;
        remainFlow -= newWin;
        if(remainFlow == 0) {
            ret = maxWin;
            break;
        }
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> playerNum >> matchNum;
        V = 2 + playerNum + matchNum;
        init();

        int totalWins = 0;
        for(int i = 0; i < playerNum; i++) cin >> wins[i];
        for(int i = 0; i < matchNum; i++) {
            cin >> match[i][0] >> match[i][1];
            if(match[i][0] == 0 || match[i][1] == 0) totalWins++;
        }

        for(int i = 0; i < matchNum; i++) {
            capacity[0][2 + i] = 1;
            for(int j = 0; j < 2; j++) {
                capacity[2 + i][2 + matchNum + match[i][j]] = 1;
            }
        }

        int lower_bound = wins[0];
        int upper_bound = wins[0] + totalWins;

        cout << solve(lower_bound, upper_bound) << "\n";
    }

	return 0;
}
