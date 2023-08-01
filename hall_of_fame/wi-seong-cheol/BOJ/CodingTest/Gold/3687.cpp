//
//  3687.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 4
 3
 6
 7
 15
 [Output]
 7 7
 6 111
 8 711
 108 7111111
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 800
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3687

#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long
const ll INF = 0x7f7f7f7f7f7f7f7f;
int t, k;
vector<ll> dp(101, INF);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    dp[8] = 10;

    for(int num = 9; num <= 100; num++) {
        for(int i = 2; i < 8; i++) {
            if (i != 6) {
                dp[num] = min(dp[num], dp[num - i] * 10 + dp[i]);
            } else {
                dp[num] = min(dp[num], dp[num - i] * 10);
            }
        }
    }
    
    cin >> t;

    while(t--) {
        cin >> k;
        string max_value = (k % 2 ? "7" : "1") + string(k / 2 - 1, '1');
        cout << dp[k] << " " << max_value << '\n';
    }

    return 0;
}
