//
//  1715.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3
 10
 20
 40
 [Output]
 100
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

using namespace std;
int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int x; cin >> x;
        pq.push(x);
    }
    while(pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans;
    
    return 0;
}
