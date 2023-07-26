//
//  19598.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 3
 0 40
 15 30
 5 10
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/19598

#include <iostream>
#include <queue>

using namespace std;
#define pii pair<int, int>
#define X first
#define Y second
int n, st, en, ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> st >> en;
        pq.push({en, -1});
        pq.push({st, 1});
    }
    int cur = 0;
    while(!pq.empty()) {
        cur += pq.top().Y; pq.pop();
        if(cur > ans) ans = cur;
    }
    cout << ans;
    
    return 0;
}
