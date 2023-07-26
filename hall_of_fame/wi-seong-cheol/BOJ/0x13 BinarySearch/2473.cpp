//
//  2473.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 -2 6 -97 -6 98
 [Output]
 -97 -2 98
 */
// 시간복잡도: O(n^2 * logn)
// 최악시간: 100,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2473

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
#define INF 1e9 + 1
int n;
ll ans[3];
ll a[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(ans, ans + 3, INF);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            auto idx = lower_bound(a, a + n, -a[i] - a[j]) - a;
            for(int k = -2; k <= 2; k++) {
                if(idx + k == i || idx + k == j) continue;
                if(idx + k < 0 || idx + k >= n) continue;
                if(abs(ans[0] + ans[1] + ans[2]) > abs(a[i] + a[j] + a[idx + k]))
                    tie(ans[0], ans[1], ans[2]) = {a[i], a[j], a[idx + k]};
            }
        }
    }
    sort(ans, ans + 3);
    for(int i = 0; i < 3; i++)
        cout << ans[i] << ' ';
    
    return 0;
}
