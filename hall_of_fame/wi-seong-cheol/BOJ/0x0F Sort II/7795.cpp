//
//  7795.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 2
 5 3
 8 1 7 3 1
 3 6 1
 3 4
 2 13 7
 103 11 290 215
 [Output]
 7
 1
 */
// 시간복잡도: O(n^2)
// 최악시간: 400,000,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/7795

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
int a[20001], b[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = m - 1; j >= 0; j--) {
                if(a[i] > b[j]) {
                    ans += j + 1;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
