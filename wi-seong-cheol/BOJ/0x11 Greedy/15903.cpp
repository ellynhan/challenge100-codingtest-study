//
//  15903.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3 1
 3 2 6
 [Output]
 16
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>

using namespace std;
#define ll long long
int n, m;
ll sum;
priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        int x; cin >> x;
        pq.push(x);
    }
    while(m--) {
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    
    return 0;
}
