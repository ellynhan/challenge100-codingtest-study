//
//  11399.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 5
 3 1 4 3 2
 [Output]
 32
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/11399

#include <iostream>
#include <algorithm>

using namespace std;
int n, sum, ans;
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        sum += a[i];
        ans += sum;
    }
    cout << ans;
    
    return 0;
}
