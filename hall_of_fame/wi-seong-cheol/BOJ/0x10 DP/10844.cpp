//
//  10844.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 1
 [Output]
 9
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 1
// Timer: 17m
// Url: https://www.acmicpc.net/problem/10844

#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1'000'000'000;
int n;
long long ans;
int d[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    fill(d[1] + 1, d[1] + 10, 1);
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j != 0) d[i][j] += d[i - 1][j - 1];
            if(j != 9) d[i][j] += d[i - 1][j + 1];
            d[i][j] %= 1000000000;
        }
    }

    for(int i = 0; i < 10; i++)
        ans += d[n][i];
    cout << ans % mod;
    
    return 0;
}
