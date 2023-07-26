//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 1 3
 2 4
 3 5
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, ans, cur, idx;
vector<pair<int, int>> event;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, t; cin >> s >> t;
        event.push_back({s, 1});
        event.push_back({t, -1});
    }
    
    sort(event.begin(), event.end());
    
    int curtime = event[0].X;
    while(1) {
        while(idx < 2*n && event[idx].X == curtime) {
            cur += event[idx].Y;
            idx++;
        }
        ans = max(ans, cur);
        if(idx == 2*n) break;
        curtime = event[idx].X;
    }
    cout << ans << '\n';
    
    return 0;
}
