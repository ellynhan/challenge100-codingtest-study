//
//  14863.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 3 1650
 500 200 200 100
 800 370 300 120
 700 250 300 90
 [Output]
 660
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14863

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, k;
pair<int, int> foot[101];
pair<int, int> cycle[101];
int d[101][100001];

int solve(int cur, int t) {
    if(cur == n) return 0;
    int& ret = d[cur][t];
    if(ret) return ret;
    ret = -1e9;
    if(t - foot[cur].X >= 0)
        ret = max(ret, solve(cur + 1, t - foot[cur].X) + foot[cur].Y);
    if(t - cycle[cur].X >= 0)
        ret = max(ret, solve(cur + 1, t - cycle[cur].X) + cycle[cur].Y);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> foot[i].X >> foot[i].Y;
        cin >> cycle[i].X >> cycle[i].Y;
    }
    cout << solve(0, k);
    
    return 0;
}
