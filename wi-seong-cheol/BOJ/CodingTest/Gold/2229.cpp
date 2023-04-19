//
//  2229.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/19.
//

/*
 [Input]
 10
 2 5 7 1 3 4 8 6 9 3
 [Output]
 20
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2229

#include <iostream>
#include <algorithm>

using namespace std;
int n, mx, mn;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        mx = mn = a[i];
        for(int j = i; j >= 0; j--) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            d[i + 1] = max(d[i + 1], d[j] + mx - mn);
        }
    }
    cout << d[n];
    
    return 0;
}
