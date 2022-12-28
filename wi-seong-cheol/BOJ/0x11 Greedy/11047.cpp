//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 10 4200
 1
 5
 10
 50
 100
 500
 1000
 5000
 10000
 50000
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 10
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11047

#include <iostream>

using namespace std;
int n, k;
int arr[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n-1; i >= 0; i--) {
        ans += k / arr[i];
        k %= arr[i];
    }
    cout << ans;
    
    return 0;
}
