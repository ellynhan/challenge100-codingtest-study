//
//  7453.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6
 -45 22 42 -16
 -41 -27 56 30
 -36 53 -37 77
 -36 30 -75 -46
 26 -38 -10 62
 -32 -54 -6 45
 [Output]
 5
 */
// 시간복잡도: O(n^2)
// 최악시간: 16,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/7453

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n, cnt;
int a[4001], b[4001], c[4001], d[4001];
int ab[16000001], cd[16000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            ab[cnt] = a[i] + b[j];
            cd[cnt++] = c[i] + d[j];
        }
    sort(ab, ab + n * n);
    sort(cd, cd + n * n);
    
    ll ans = 0;
    for(int i = 0; i < n*n; i++)
        ans += upper_bound(cd, cd + n*n, -ab[i]) - lower_bound(cd, cd + n*n, -ab[i]);
    cout << ans;
    
    return 0;
}
