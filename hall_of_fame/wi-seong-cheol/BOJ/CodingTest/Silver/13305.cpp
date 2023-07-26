//
//  13305.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 4
 2 3 1
 5 2 4 1
 [Output]
 18
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/13305

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int SIZE = 100'001;
ll ans;
int n, mn = 0x7f7f7f7f;
int gas[SIZE];
int road[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        cin >> road[i];
    for(int i = 0; i < n; i++)
        cin >> gas[i];
    for(int i = 0; i < n - 1; i++) {
        mn = min(mn, gas[i]);
        ans += (ll)road[i] * (ll)mn;
    }
    cout << ans;
    
    return 0;
}
