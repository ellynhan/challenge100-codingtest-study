//
//  1026.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 5
 1 1 1 6 0
 2 7 8 3 1
 [Output]
 18
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1026

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[51], b[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i] * b[i];
    cout << ans;
    
    return 0;
}
