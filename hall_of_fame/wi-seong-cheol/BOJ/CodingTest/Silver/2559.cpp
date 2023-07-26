//
//  2559.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 10 2
 3 -2 -4 -9 0 3 7 13 8 -3
 [Output]
 21
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2559

#include <iostream>
#include <algorithm>

using namespace std;
const int MIN = -0x7f7f7f7f;
int ans = MIN;
int n, k;
int a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int en = 0;
    int sum = 0;
    for(int st = 0; st <= n - k; st++) {
        while(en - st < k) {
            sum += a[en++];
        }
        ans = max(ans, sum);
        sum -= a[st];
    }
    cout << ans;
    
    return 0;
}
