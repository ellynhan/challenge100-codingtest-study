//
//  1758.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 4
 3
 3
 3
 3
 [Output]
 6
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1758

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n;
ll ans;
ll a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<>());
    for(ll i = 0; i < n; i++) {
        if(a[i] - i < 0) continue;
        ans += a[i] - i;
    }
    cout << ans;
    
    return 0;
}
