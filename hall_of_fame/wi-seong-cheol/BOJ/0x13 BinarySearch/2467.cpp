//
//  2467.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 -99 -2 -1 4 98
 [Output]
 -99 98
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2467

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[100001];
int ans1 = 1e9+1;
int ans2 = 1e9+1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        auto idx = lower_bound(a, a + n, -a[i]) - a;
        if(idx + 1 < n && i != idx + 1 && abs(a[i] + a[idx + 1]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[idx + 1];
        }
        if(idx < n && i != idx && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx];
        }
        if(idx != 0 && i != idx-1 && abs(a[i] + a[idx - 1]) < abs(ans1 + ans2)){
            ans1 = a[i];
            ans2 = a[idx - 1];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2;
    
    return 0;
}
