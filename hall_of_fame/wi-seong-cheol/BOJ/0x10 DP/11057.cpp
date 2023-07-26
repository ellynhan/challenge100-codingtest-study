//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 1
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/11057

#include <iostream>
#include <numeric>

using namespace std;
#define ll long long
const int mod = 10007;
int n;
ll d[1001][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        d[i][0] = 1;
        for(int j = 1; j < 10; j++)
            d[i][j] = (d[i][j - 1] + d[i - 1][j]) % mod;
    }
    cout << accumulate(d[n], d[n] + 10, 0) % mod;
    
    return 0;
}
