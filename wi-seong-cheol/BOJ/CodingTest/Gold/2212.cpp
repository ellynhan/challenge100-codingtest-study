//
//  2212.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 10
 5
 20 3 14 6 7 8 18 10 12 15
 [Output]
 7
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2212

#include <iostream>
#include <algorithm>

using namespace std;
int n, k, ans;
int a[10001];
int dif[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    if(k >= n) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++)
        dif[i] = a[i + 1] - a[i];
    sort(dif, dif + n - 1);
    for(int i = 0; i < n - k; i++)
        ans += dif[i];
    cout << ans;
    
    return 0;
}
