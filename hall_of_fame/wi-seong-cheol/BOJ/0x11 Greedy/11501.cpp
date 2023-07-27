//
//  11501.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 3
 10 7 6
 3
 3 5 9
 5
 1 1 3 1 2
 [Output]
 0
 10
 5
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Silver 2
// Timer: 7m
// Url: https://www.acmicpc.net/problem/11501

#include <iostream>

using namespace std;
#define ll long long
int t, n;
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int max_val = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(max_val < a[i]) max_val = a[i];
            ans += max_val - a[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}
