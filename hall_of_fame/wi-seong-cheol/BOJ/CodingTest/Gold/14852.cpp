//
//  14852.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 3
 [Output]
 22
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14852

#include <iostream>

using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n;
ll d[1000001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;
    for(int i = 3; i <= n; i++) {
        d[i][1] = (d[i - 3][0] + d[i - 1][1]) % mod;
        d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % mod;
    }
    
    cout << d[n][0];
    
    return 0;
}
