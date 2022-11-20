//
//  6549.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 7 2 1 4 5 1 3 3
 4 1000 1000 1000 1000
 0
 [Output]
 8
 4000
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Platinum 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/6549

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
#define X first
#define Y second
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        ll ans = 0;
        stack<pair<int, int>> S;
        for(int i = 0; i < n; i++) {
            int h; cin >> h;
            int idx = i;
            while(!S.empty() && h <= S.top().X) {
                ans = max(ans, 1LL * (i - S.top().Y) * S.top().X);
                idx = S.top().Y;
                S.pop();
            }
            S.push(make_pair(h, idx));
        }
        while(!S.empty()) {
            ans = max(ans, 1LL * (n - S.top().Y) * S.top().X);
            S.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
