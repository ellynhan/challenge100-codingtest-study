//
//  2098.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 4
 0 10 15 20
 5 0 9 10
 6 13 0 12
 8 8 9 0
 [Output]
 35
 */
// 시간복잡도: O(n)
// 최악시간: 1,048,576
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/123

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e9;
int n, END;
int cost[16][16];
int dp[16][1 << 16];

int tsp(int cur, int vis) {
    if(vis == END) {
        if(cost[cur][0] > 0)
            return cost[cur][0];
        return INF;
    }
    
    if(dp[cur][vis] != 0) return dp[cur][vis];
    
    dp[cur][vis] = INF;
    
    for(int i = 0; i < n; i++) {
        if(cost[cur][i] == 0) continue;
        if(vis & (1 << i)) continue;
        
        int val = tsp(i, vis | 1 << i);
        dp[cur][vis] = min(dp[cur][vis], cost[cur][i] + val);
    }
    
    return dp[cur][vis];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    END = (1 << n) - 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];
    
    cout << tsp(0, 1);
    
    return 0;
}
