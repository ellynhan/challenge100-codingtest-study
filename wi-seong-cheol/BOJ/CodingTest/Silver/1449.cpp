//
//  1449.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

/*
 [Input]
 3 1
 3 2 1
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1449

#include <iostream>
#include <algorithm>

using namespace std;
int n, L, ans;
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> L;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int cur = a[0];
    ans++;
    for(int i = 1; i < n; i++) {
        if(a[i] - cur > L - 1) {
            cur = a[i];
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
