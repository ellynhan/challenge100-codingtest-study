//
//  2688.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 1
 64
 [Output]
 97082021465
 */
// 시간복잡도: O(n^2)
// 최악시간: 6,400
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2688

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int t, n;
ll d[65][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(d[1], d[1] + 10, 1);
    for(int k = 2; k <= 64; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j <= i; j++) {
                d[k][i] += d[k - 1][j];
            }
        }
    }
        
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(int i = 0; i < 10; i++)
            ans += d[n][i];
        cout << ans << '\n';
    }
    
    return 0;
}
