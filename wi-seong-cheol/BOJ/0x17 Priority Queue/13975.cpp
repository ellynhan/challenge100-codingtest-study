//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 4
 40 30 30 50
 15
 1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
 [Output]
 300
 826
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Gold 4
// Timer: 14m
// Url: https://www.acmicpc.net/problem/13975

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll ans = 0;
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            pq.push(x);
        }
        while(pq.size() != 1) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << '\n';
    }
    return 0;
}
