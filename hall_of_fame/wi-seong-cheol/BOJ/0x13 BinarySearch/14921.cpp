//
//  14921.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 -101 -3 -1 5 93
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/14921

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int ans = 0x7f7f7f7f;
int a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        auto idx = lower_bound(a + i + 1, a + n, -a[i]) - a;
        
        if(idx < n && abs(a[i] + a[idx]) < abs(ans)) {
            ans = a[i] + a[idx];
        }
        
        if(idx + 1 < n && abs(a[i] + a[idx + 1]) < abs(ans)) {
            ans = a[i] + a[idx + 1];
        }
        
        if(idx - 1 != i && abs(a[i] + a[idx - 1]) < abs(ans)) {
            ans = a[i] + a[idx - 1];
        }
    }
    cout << ans;
    
    return 0;
}
