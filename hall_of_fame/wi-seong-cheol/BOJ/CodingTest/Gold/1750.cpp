//
//  1750.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/21.
//

/*
 [Input]
 3
 2
 4
 3
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 5,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1750

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
#define ll long long
const int mod = 10000003;
int n;
ll a[51];
ll d[51][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        d[i][a[i]] = 1;
        if(i == 0) continue;
        for(int j = 1; j <= a[i]; j++)
            d[i][j] += d[i - 1][j];
        for(int j = 1; j <= a[i]; j++)
            d[i][gcd(a[i], j)] = (d[i][gcd(a[i], j)] + d[i - 1][j]) % mod;
    }
    cout << d[n - 1][1];

    return 0;
}
