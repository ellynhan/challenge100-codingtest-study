//
//  6198.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 6
 10
 3
 7
 4
 12
 2
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 80000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>

using namespace std;
#define ll long long
stack<ll> S;
int n;
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        ll h; cin >> h;
        while(!S.empty() && S.top() <= h)
            S.pop();
        ans += S.size();
        S.push(h);
    }
    cout << ans;
    
    return 0;
}
